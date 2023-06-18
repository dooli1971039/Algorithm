#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> arr;
vector<bool> visited;

void dfs(int n, int next) {
    if (visited[next]) {
        return;
    }

    visited[next] = true;
    for (int i = 1; i <= n; i++) {
        if (arr[next][i]) { // 연결되어있을 때
            dfs(n, i);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    arr.assign(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }

    visited.assign(n + 1, false);
    dfs(n, 1); // 1번부터 시작

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            cnt++;
        }
    }
    cout << cnt - 1;
    return 0;
}