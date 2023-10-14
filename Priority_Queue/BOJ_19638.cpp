#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, h, t;
    cin >> n >> h >> t;

    priority_queue<int> pq;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    int cnt = 0;
    while (pq.top() >= h) {
        if (t == cnt || pq.top() == 1) {
            cout << "NO\n" << pq.top();
            return 0;
        }

        int num = pq.top() / 2;
        pq.pop();
        pq.push(num);
        cnt++;
    }

    cout << "YES\n" << cnt;
}