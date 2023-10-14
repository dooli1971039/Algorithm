#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ci;
const int INF = 987654321;
int v, e, k;

vector<int> dijkstra(vector<vector<ci>> &graph) {
    priority_queue<ci, vector<ci>, greater<>> pq; // 가중치, 노드번호
    vector<int> dist(v + 1, INF);

    dist[k] = 0;
    pq.push({0, k}); // 가중치, 노드번호

    while (!pq.empty()) {
        int cost = pq.top().first;  // 현재 정점까지의 가중치
        int node = pq.top().second; // 현재 탐색하려는 정점
        pq.pop();

        if (cost > dist[node]) { // 갱신 필요 X
            continue;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int nextCost = graph[node][i].second;

            if (cost + nextCost < dist[nextNode]) {
                dist[nextNode] = cost + nextCost;
                pq.push({cost + nextCost, nextNode});
            }
        }
    }

    return dist;
}

int main() {
    cin >> v >> e >> k;

    vector<vector<ci>> graph(v + 1, vector<ci>(0));

    int a, b, w;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    vector<int> dist = dijkstra(graph);

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
}
