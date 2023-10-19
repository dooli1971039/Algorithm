#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<int>> melt;
queue<pair<int, int>> q;
bool check = false;
int cnt = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int checkDir(int r, int c) {
    int zero = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (arr[nr][nc] == 0)
            zero++;
    }
    return zero;
}

void calcMelt() {
    int num;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (arr[i][j] == 0)
                continue;
            num = checkDir(i, j); // 얼마나 녹아야 하는지 계산
            if (num > arr[i][j])
                num = arr[i][j];

            melt[i][j] = num;
        }
    }
}

void meltSnow() {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (arr[i][j] == 0)
                continue;
            arr[i][j] -= melt[i][j]; // 빙산 녹음

            if (arr[i][j] > 0) {
                cnt++;
                if (!check) {
                    q.push({i, j});
                    check = true;
                }
            }
            melt[i][j] = 0; // 다시 초기화
        }
    }
}

bool checkDivided() {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[q.front().first][q.front().second] = true;

    int count = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + r;
            int nc = dc[i] + c;

            if (!visited[nr][nc] && arr[nr][nc] > 0) {
                q.push({nr, nc});
                visited[nr][nc] = true;
                count++;
            }
        }
    }

    if (count == cnt) { // 아직 하나
        return false;
    } else { // 나눠짐
        return true;
    }
}

int main() {
    cin >> n >> m;
    arr.assign(n, vector<int>(m, 0));
    melt.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int time = 1;
    while (true) {
        // 1.빙산 얼마나 녹을지 계산
        calcMelt();
        // 2.빙산 녹음
        meltSnow();
        // 3. 다 녹았는지 체크
        if (cnt == 0) {
            cout << 0;
            return 0;
        }
        // 4.덩어리 계산
        if (checkDivided()) {
            cout << time;
            return 0;
        }

        time++;
        // 초기화
        cnt = 0;
        check = false;
    }
}