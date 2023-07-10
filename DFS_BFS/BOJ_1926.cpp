#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int arr[505][505];      // 입력받은 부분
bool visited[505][505]; // 방문한 곳
int n, m;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true; // 색칠하기
    int num = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && arr[nr][nc] == 1 && visited[nr][nc] == false) {
                q.push({nr, nc});
                visited[nr][nc] = true;
                num++;
            }
        }
    }

    return num;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == false && arr[i][j] == 1) {
                maxArea = max(bfs(i, j), maxArea);
                cnt++;
            }
        }
    }

    cout << cnt << "\n" << maxArea;
}