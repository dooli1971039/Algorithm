#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, tmp;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    while (n--) {
        cin >> tmp;
        pq.push(tmp);
    }

    int compare = 0;
    while (pq.size() > 1) {
        int p1 = pq.top();
        pq.pop();
        int p2 = pq.top();
        pq.pop();

        compare += (p1 + p2);
        pq.push(p1 + p2);
    }

    cout << compare;
}