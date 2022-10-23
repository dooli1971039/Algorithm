#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    queue<int> answer;
    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        answer.push(q.front());
        q.pop();
    }

    cout << "<" << answer.front();
    while (answer.size() > 1) {
        answer.pop();
        cout << ", " << answer.front();
    }
    cout << ">";
}