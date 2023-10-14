#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ci;
const int INF = 987654321;

vector<int> dijkstra(int n, int st, vector<vector<ci>> &graph) {
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<int> dist(n + 1, INF);

    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dist[node])
            continue;

        for (int i = 0; i < graph[node].size(); i++) {
            int nextCost = graph[node][i].second + cost;
            int nextNode = graph[node][i].first;

            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    return dist;
}

void solution() {
    int n, d, c;
    cin >> n >> d >> c;

    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    int a, b, s;
    for (int i = 0; i < d; i++) {
        cin >> a >> b >> s;
        graph[b].push_back({a, s});
    }

    vector<int> dist = dijkstra(n, c, graph);

    int cnt = 0;
    int time = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] != INF) {
            cnt++;
            time = max(time, dist[i]);
        }
    }
    cout << cnt << ' ' << time << '\n';
    return;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        solution();
    }
}