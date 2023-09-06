#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순으로 되게

    for (auto num : scoville) {
        pq.push(num);
    }

    int cnt = 0;
    while (pq.top() < K) {
        if (pq.size() <= 1) {
            return -1;
        }

        int first = pq.top();
        pq.pop();
        int second = 2 * pq.top();
        pq.pop();
        pq.push(first + second);
        cnt++;
    }

    return cnt;
}