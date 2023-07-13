#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int dist[101][101];
int n, m;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int bfs() {
    queue<pair<int, int>> q;

    q.push({1, 1});
    dist[1][1] = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {

            int nr = p.first + dr[i];
            int nc = p.second + dc[i];

            // 인덱스 체크 && 이동할 수 있는 칸 && 아직 방문 안 했을 경우
            if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && arr[nr][nc] == 1 && dist[nr][nc] == 0) {
                q.push({nr, nc});
                dist[nr][nc] = dist[p.first][p.second] + 1;
            }
        }
    }

    return dist[n][m];
}

int main() {
    cin >> n >> m;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;

        for (int j = 1; j <= m; j++) {
            arr[i][j] = (str[j - 1] - '0');
        }
    }

    cout << bfs();
}