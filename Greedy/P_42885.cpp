#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    int start = 0;
    int end = people.size() - 1;
    int answer = 0;

    while (start <= end) {
        if (start == end) {
            answer++;
            break;
        }
        if (people[start] + people[end] <= limit) {
            answer++;
            start++;
            end--;
        } else { // limit를 초과했을 때
            answer++;
            end--;
        }
    }

    return answer;
}