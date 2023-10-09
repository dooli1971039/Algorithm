#include <iostream>
#include <vector>

using namespace std;

int parent[501];
bool cycle[501];

void init() {
    for (int i = 0; i < 501; i++) {
        parent[i] = -1;
        cycle[i] = false;
    }
}

int find(int node) {
    if (parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);
}

void unionNode(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) {
        // 사이클
        cycle[parentA] = true;
        cycle[parentB] = true;
        return;
    }

    if (parent[parentA] <= parent[parentB]) {
        parent[parentA] += parent[parentB];
        parent[parentB] = parentA;
    } else {
        parent[parentB] += parent[parentA];
        parent[parentA] = parentB;
    }
}

void solution(int tc, int n, int m) {
    init();

    int a, b;
    while (m--) {
        cin >> a >> b;

        unionNode(a, b);
    }

    int tree = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0 && !cycle[i])
            tree++;
    }

    if (tree == 0) {
        cout << "Case " << tc << ": No trees.\n";
    } else if (tree == 1) {
        cout << "Case " << tc << ": There is one tree.\n";
    } else {
        cout << "Case " << tc << ": A forest of " << tree << " trees.\n";
    }
    return;
}

int main() {
    int n, m;
    int tc = 1;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        solution(tc, n, m);
        tc++;
    }
}