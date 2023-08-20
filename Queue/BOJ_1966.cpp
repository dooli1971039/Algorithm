#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution() {
    int n, m;
    cin >> n >> m;
    queue<int> pageQueue;
    vector<int> pageVector; // 중요도 정렬을 위함

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pageQueue.push(tmp);
        pageVector.push_back(tmp);
    }
    sort(pageVector.begin(), pageVector.end());

    int cnt = 1;
    while (true) {
        if (pageVector[pageVector.size() - 1] == pageQueue.front()) { // 이때 out
            if (m == 0) {
                return cnt;
            } else {
                pageQueue.pop();
                pageVector.pop_back();
                cnt++;
                m--;
                continue;
            }
        }

        auto front = pageQueue.front();
        pageQueue.pop();
        pageQueue.push(front);
        m--;
        if (m < 0)
            m = pageQueue.size() - 1;
    }

    return cnt;
}

int main() {
    int testCase;
    cin >> testCase;

    while (testCase--) {
        cout << solution() << "\n";
    }
}