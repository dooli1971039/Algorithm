#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(int n, vector<int> node[]) {
    bool dist[n + 1] = {
        false,
    };
    queue<int> q;

    q.push(1);
    dist[1] = true;

    while (!q.empty()) {
        int com = q.front();
        q.pop();

        for (int next : node[com]) {
            if (!dist[next]) {
                q.push(next);
                dist[next] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += dist[i];
    return cnt - 1;
}

int main() {
    int n, link;
    cin >> n >> link;
    vector<int> node[n + 1];

    int a, b;
    for (int i = 0; i < link; i++) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    cout << bfs(n, node);
}