#include <iostream>
#include <queue>
using namespace std;

int arr[100001];
int n, k;

int returnNextPosition(int type, int num) {
    if (type == 0)
        return num - 1;
    else if (type == 1)
        return num + 1;
    else
        return num * 2;
}

int bfs(int n, int k) {
    queue<int> q;

    q.push(n);
    arr[n] = 1;

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {

            int next = returnNextPosition(i, idx);

            // 인덱스 체크 && 아직 방문 안 했을 경우
            if (next >= 0 && next <= 100000 && arr[next] == 0) {
                q.push(next);
                arr[next] = arr[idx] + 1;
            }
        }
    }

    return arr[k] - 1; // 처음 시작할 때 1초로 두고 했기 때문에 -1 필요
}

int main() {
    cin >> n >> k;

    cout << bfs(n, k);
}