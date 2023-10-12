#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int node) {
    if (parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);
}

bool unionDot(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) {
        // 사이클
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
    int n, m;
    cin >> n >> m;
    parent.assign(n, -1);

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;

        if (!unionDot(a, b)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}