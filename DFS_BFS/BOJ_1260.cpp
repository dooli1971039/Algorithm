#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, v;
vector<int> arr[1001];
int visited[1001];

void dfs(int node) {
    visited[node] = true;
    cout << node << ' ';

    for (auto next : arr[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs() {
    queue<int> q;
    vector<int> visited(n + 1, false);

    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << ' ';

        for (auto next : arr[node]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;

    int v1, v2;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;

        arr[v1].push_back(v2);
        arr[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
        sort(arr[i].begin(), arr[i].end());

    dfs(v);

    cout << "\n";

    bfs();
}