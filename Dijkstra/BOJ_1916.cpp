#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 987654321;

vector<int> dijkstra(int st, vector<vector<ci>> arr) {
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<int> dist(arr.size(), INF);

    dist[st] = 0;
    pq.push({0, st}); // st까지 가는 가중치, st

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // 여기 등호 들어가면 안 됨
        if (cost > dist[node])
            continue;

        for (int i = 0; i < arr[node].size(); i++) {
            int nextNode = arr[node][i].first;
            int nextCost = cost + arr[node][i].second;

            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ci>> arr(n + 1, vector<ci>(0));

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({b, c}); // 정점, 가중치
    }

    int st, ed;
    cin >> st >> ed;
    vector<int> dist = dijkstra(st, arr);

    cout << dist[ed];
}