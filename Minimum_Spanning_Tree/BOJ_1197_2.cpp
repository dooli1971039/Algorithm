#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int v, e; // 정점, 간선
vector<int> parent;

int find(int node) {
    if (parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);
}

bool unionNode(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) {
        // 사이클 발생
        return false;
    }

    if (parent[pa] <= parent[pb]) {
        parent[pa] += parent[pb];
        parent[pb] = pa;
    } else {
        parent[pb] += parent[pa];
        parent[pa] = pb;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e;
    parent.assign(v + 1, -1);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    int a, b, c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }

    int costSum = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        pair<int, int> nodes = pq.top().second;
        pq.pop();

        if (unionNode(nodes.first, nodes.second)) {
            costSum += cost;
        }
    }
    cout << costSum;
}