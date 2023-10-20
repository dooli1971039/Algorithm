#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(100001, -1);

    queue<int> q;
    q.push(n);
    arr[n] = 0;

    int pos = -1;
    int next = -1;
    while (!q.empty()) {
        pos = q.front();
        q.pop();

        next = 2 * pos;
        if (next <= 100000 && arr[next] == -1) {
            arr[next] = arr[pos];
            q.push(next);
        }

        next = pos - 1;
        if (next >= 0 && arr[next] == -1) {
            arr[next] = arr[pos] + 1;
            q.push(next);
        }

        next = pos + 1;
        if (next <= 100000 && arr[next] == -1) {
            arr[next] = arr[pos] + 1;
            q.push(next);
        }
    }

    cout << arr[k];
}