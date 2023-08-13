#include <iostream>
#include <queue>

using namespace std;
int f, s, g, u, d;
int visited[1000001];

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 전체 f층, s에 있는데, g로 가려함
    // u층 위로 가거나, d층 아래로 감
    cin >> f >> s >> g >> u >> d;

    queue<int> floor;
    floor.push(s);
    visited[s] = 1; // 1에서 시작하기 때문에 출력 시 -1해야 함

    while (!floor.empty()) {
        int cur = floor.front();
        floor.pop();

        if (cur + u <= f && !visited[cur + u]) {
            floor.push(cur + u);
            visited[cur + u] = visited[cur] + 1;
        }
        if (cur - d >= 1 && !visited[cur - d]) {
            floor.push(cur - d);
            visited[cur - d] = visited[cur] + 1;
        }
    }

    if (visited[g] == 0) {
        cout << "use the stairs";
    } else {
        cout << visited[g] - 1;
    }
}