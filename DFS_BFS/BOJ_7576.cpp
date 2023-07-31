#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs(queue<pair<int, int>> &que, vector<vector<int>> &arr, int cnt, int n, int m) {
    int time = 1;

    while (!que.empty()) {
        pair<int, int> tmp = que.front();
        que.pop();

        time = arr[tmp.first][tmp.second];
        for (int i = 0; i < 4; i++) {
            int nx = tmp.second + dx[i];
            int ny = tmp.first + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[ny][nx] == 0) {
                que.push({ny, nx});
                arr[ny][nx] = time + 1;
                cnt--;
            }
        }
    }

    return (cnt == 0 ? time - 1 : -1);
}

int main() {
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    vector<vector<int>> arr(m, vector<int>(n, 0));
    queue<pair<int, int>> que;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) { // 익은 토마토
                que.push({i, j});
            } else if (arr[i][j] == 0) {
                cnt++;
            }
        }
    }

    cout << bfs(que, arr, cnt, n, m);
}