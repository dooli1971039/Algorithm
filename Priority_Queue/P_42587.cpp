#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue<pair<int, int>> alpha;
    for (int i = 0; i < priorities.size(); i++) {
        if (i == location) {
            alpha.push({-1, priorities[i]}); // 결과 확인을 위함
        } else {
            alpha.push({i, priorities[i]}); // 번호와 우선순위
        }
        pq.push(priorities[i]);
    }
    int cnt = 0;
    while (true) {
        int big = pq.top(); // 우선순위 제일 높은거
        pq.pop();

        while (alpha.front().second != big) {
            auto fr = alpha.front();
            alpha.pop();
            alpha.push(fr);
        }

        auto out = alpha.front();
        alpha.pop();
        cnt++;
        if (out.first == -1) {
            break;
        }
    }

    return cnt;
}