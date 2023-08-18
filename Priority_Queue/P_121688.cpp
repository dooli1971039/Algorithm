/* PCCP 모의고사 2회 2번
 * https://school.programmers.co.kr/learn/courses/15009/lessons/121688
 */

#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ability, int number) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < ability.size(); i++) {
        pq.push(ability[i]);
    }

    while (number--) {
        int people1 = pq.top();
        pq.pop();
        int people2 = pq.top();
        pq.pop();

        pq.push(people1 + people2);
        pq.push(people1 + people2);
    }

    int answer = 0;
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    return answer;
}