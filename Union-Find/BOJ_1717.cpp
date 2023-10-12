#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int findParent(int node) {
    if (parent[node] < 0) {
        return node; // 루트 정점
    }

    return parent[node] = findParent(parent[node]); // 그래프 압축하여 루트 정점 찾기
}

void unionInput(int x, int y) {
    int nodeX = findParent(x);
    int nodeY = findParent(y);

    if (nodeX == nodeY) { // 이미 같은 집합
        return;
    }

    if (parent[nodeX] < parent[nodeY]) { // nodeX 쪽 집합이 더 큰 경우
        parent[nodeX] += parent[nodeY];
        parent[nodeY] = nodeX;
    } else {
        parent[nodeY] += parent[nodeX];
        parent[nodeX] = nodeY;
    }
    // 위와 같이 갱신을 하면, find를 한 번 거쳐야 루트 정점이 갱신된다.
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    parent.assign(n + 1, -1); // 1~n

    int cmd, a, b;
    while (m--) {
        cin >> cmd >> a >> b;

        if (cmd == 0) { // union 연산
            unionInput(a, b);
        } else { // 같은 집합에 포함되어있는지
            // parent[a], parent[b]가 아닌 이유 -> 루트 정점의 경우 parent값이 음수이다.
            // 따라서 정점을 구하려면 갱신이 필요함
            if (findParent(a) == findParent(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}