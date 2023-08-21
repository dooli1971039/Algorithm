#include <iostream>
#include <vector>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int r, c, t;
vector<vector<int>> arr;
vector<int> airCleaner;

void extendsDust() {
    vector<vector<int>> ccopy(r + 1, vector<int>(c + 1, 0));
    copy(arr.begin(), arr.end(), ccopy.begin()); // 이번에 확산되며 생긴 먼지인지 아닌지 구분하려고 생성

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (ccopy[i][j] <= 0)
                continue; // 비어있던가, 공기청정기이면 continue;

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr >= 1 && nc >= 1 && nr <= r && nc <= c && ccopy[nr][nc] != -1) {
                    arr[nr][nc] += (ccopy[i][j] / 5);
                    cnt++;
                }
            }
            arr[i][j] -= (ccopy[i][j] / 5) * cnt;
        }
    }
}

void operateTopAirCleaner() {
    // 반시계 방향으로 회전
    for (int i = airCleaner[0] - 1; i > 1; i--) {
        arr[i][1] = arr[i - 1][1];
    }

    for (int i = 1; i < c; i++) {
        arr[1][i] = arr[1][i + 1];
    }

    for (int i = 1; i < airCleaner[0]; i++) {
        arr[i][c] = arr[i + 1][c];
    }

    for (int i = c; i > 2; i--) {
        arr[airCleaner[0]][i] = arr[airCleaner[0]][i - 1];
    }
    arr[airCleaner[0]][2] = 0;
}

void operateBottomAirCleaner() {
    // 시계 방향으로 회전;
    for (int i = airCleaner[1] + 1; i < r; i++) {
        arr[i][1] = arr[i + 1][1];
    }

    for (int i = 1; i < c; i++) {
        arr[r][i] = arr[r][i + 1];
    }

    for (int i = r; i > airCleaner[1]; i--) {
        arr[i][c] = arr[i - 1][c];
    }

    for (int i = c; i > 2; i--) {
        arr[airCleaner[1]][i] = arr[airCleaner[1]][i - 1];
    }
    arr[airCleaner[1]][2] = 0;
}

void operateAirCleaner() {
    operateTopAirCleaner();
    operateBottomAirCleaner();
}

int accumulateDust() {
    int ssum = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (arr[i][j] == -1)
                continue;
            ssum += arr[i][j];
        }
    }
    return ssum;
}

int main() {
    cin >> r >> c >> t;
    arr.assign(r + 1, vector<int>(c + 1, 0));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                airCleaner.push_back(i);
            }
        }
    }

    while (t--) {
        extendsDust();       // 1. 미세먼지 확장
        operateAirCleaner(); // 2. 공기청정기 작동
    }

    // 3. 전체에 남아있는 미세먼지 양 구하여 출력
    cout << accumulateDust();

    return 0;
}