#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int m, n, k;

void bfs(vector<vector<bool>> &arr, vector<vector<bool>> &visited, int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        pair<int, int> point = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + point.first;
            int nc = dc[i] + point.second;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && arr[nr][nc] && !visited[nr][nc]) {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
}

int solution() {
    cin >> m >> n >> k; // 열, 행, 배추 개수

    vector<vector<bool>> arr(n, vector<bool>(m, false));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> baechu;

    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> c >> r;
        baechu.push_back({r, c});
        arr[r][c] = true;
    }

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int r = baechu[i].first;
        int c = baechu[i].second;

        if (!visited[r][c]) {
            cnt++;
            bfs(arr, visited, r, c);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cout << solution() << '\n';
    }
}