#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int solution() {
    int len;
    cin >> len;

    vector<vector<int>> arr(len, vector<int>(len, 0)); // 0은 이동 전
    queue<pair<int, int>> q;

    int stR, stC;
    cin >> stR >> stC;
    q.push({stR, stC});
    arr[stR][stC] = 1;

    int enR, enC;
    cin >> enR >> enC;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first == enR && p.second == enC) {
            break;
        }

        for (int i = 0; i < 8; i++) {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];

            if (nr >= 0 && nc >= 0 && nr < len && nc < len && arr[nr][nc] == 0) {
                q.push({nr, nc});
                arr[nr][nc] = arr[p.first][p.second] + 1;
            }
        }
    }

    return arr[enR][enC] - 1;
}

int main() {
    int testCase;
    cin >> testCase;

    while (testCase--) {
        cout << solution() << '\n';
    }
}