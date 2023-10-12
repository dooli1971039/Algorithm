#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef tuple<int, int, int> tp;

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
    vector<tp> vertex;

    int a, b, c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        vertex.push_back({c, a, b});
    }
    sort(vertex.begin(), vertex.end());

    int costSum = 0;
    int edge = 0;
    for (int i = 0; i < e; i++) {

        tie(c, a, b) = vertex[i];
        if (unionNode(a, b)) {
            costSum += c;
            edge++;
            if (edge == v - 1) {
                cout << costSum;
                break;
            }
        }
    }
}