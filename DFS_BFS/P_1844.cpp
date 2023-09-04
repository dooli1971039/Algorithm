#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

// 0은 벽, 1은 길
int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        auto point = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + point.first;
            int nc = dc[i] + point.second;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && maps[nr][nc] == 1 && dist[nr][nc] == -1) {
                q.push({nr, nc});
                dist[nr][nc] = dist[point.first][point.second] + 1;
            }
        }
    }

    return dist[n - 1][m - 1];
}