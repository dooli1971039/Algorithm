#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> pq;
    int n, tmp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) {
            if (pq.size() == 0) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(tmp);
        }
    }
}