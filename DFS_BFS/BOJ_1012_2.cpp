#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int m, n, k;
bool arr[50][50];
bool visited[50][50];

void dfs(int r, int c) {
    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = dr[i] + r;
        int nc = dc[i] + c;

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && arr[nr][nc] && !visited[nr][nc]) {
            dfs(nr, nc);
        }
    }
}

int solution() {
    cin >> m >> n >> k; // 열, 행, 배추 개수

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
            dfs(r, c);
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
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                arr[i][j] = false;
                visited[i][j] = false;
            }
        }
    }
}