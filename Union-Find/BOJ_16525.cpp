#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> money;

int find(int node) {
    if (parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);
}

void unionFriend(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb)
        return; // 이미 친구

    if (parent[pa] <= parent[pb]) {
        parent[pa] += parent[pb];
        parent[pb] = pa;
    } else {
        parent[pb] += parent[pa];
        parent[pa] = pb;
    }

    money[pa] = money[pb] = min(money[pa], money[pb]);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    parent.assign(n + 1, -1);
    money.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> money[i];

    // 1. 친구 관계 만들기
    int a, b;
    while (m--) {
        cin >> a >> b;
        if (a == b)
            continue;

        unionFriend(a, b);
    }

    // 2. 비용 계산하기
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0)
            cost += money[i];
    }

    if (cost <= k)
        cout << cost;
    else
        cout << "Oh no";
}