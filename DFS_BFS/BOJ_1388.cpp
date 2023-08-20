#include <iostream>
using namespace std;

int n, m;
char arr[50][50];
int visit[50][50];

void dfs(int cnt, int r, int c) {
    visit[r][c] = cnt;

    if (arr[r][c] == '-') {
        if (c + 1 < m && arr[r][c + 1] == '-') {
            dfs(cnt, r, c + 1);
        }
    } else {
        if (r + 1 < n && arr[r + 1][c] == '|') {
            dfs(cnt, r + 1, c);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visit[i][j] == 0) { // 아직 방문 안 했을 때
                cnt++;
                dfs(cnt, i, j);
            }
        }
    }

    cout << cnt;
}