#include <cmath>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

typedef pair<double, double> ci;
typedef tuple<double, int, int> tp;

int n, m;
vector<int> parent;

int find(int node) {
    if (parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);
}

bool unionStar(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) {
        return false; // 사이클
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

    cin >> n >> m;
    vector<ci> point(n + 1, {0, 0});
    priority_queue<tp, vector<tp>, greater<tp>> pq;
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        cin >> point[i].first >> point[i].second;

        for (int j = 1; j < i; j++) {
            double cost = sqrt((point[i].first - point[j].first) * (point[i].first - point[j].first) +
                               (point[i].second - point[j].second) * (point[i].second - point[j].second));
            pq.push({cost, j, i});
        }
    }

    int n1, n2;
    int cnt = 0;
    double len = 0;
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        if (unionStar(n1, n2))
            cnt++;
    }

    double c;
    int a, b;
    while (!pq.empty()) {
        tie(c, a, b) = pq.top();
        pq.pop();

        if (unionStar(a, b)) {
            len += c;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << len;
}