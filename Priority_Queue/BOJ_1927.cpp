#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<>> pq;
    ll tmp;
    while (n--) {
        cin >> tmp;
        if (tmp == 0) {
            if (pq.empty())
                cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(tmp);
        }
    }
}