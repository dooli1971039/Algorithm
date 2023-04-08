#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(const int &x1, const int &x2) { // x1이 부모노드를 가리키고, x2가 자식 노드를 가리킴
        // true일 때 swap이 이루어짐
        if (abs(x1) != abs(x2)) {
            return abs(x2) < abs(x1); // 절대값이 다르면 절댓값 작은 수를 앞으로
        }
        // 절대값이 동일하면 값이 작은수를 앞으로
        return x2 < x1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, cmp> pq;
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