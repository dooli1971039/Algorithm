#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m;
vector<int> arr[1001];
int visited[1001];

int main() {
    cin >> n >> m;

    int node1, node2;
    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;

        arr[node1].push_back(node2);
        arr[node2].push_back(node1);
    }

    queue<int> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;

        cnt++;
        q.push(i);
        visited[i] = cnt;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto next : arr[node]) {
                if (visited[next])
                    continue;
                q.push(next);
                visited[next] = visited[node];
            }
        }
    }

    cout << cnt;
    return 0;
}