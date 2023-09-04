#include <queue>
#include <string>
#include <vector>
using namespace std;

int calcDay(int progress, int speed) {
    int left = 100 - progress;

    if (left % speed == 0) {
        return left / speed;
    } else {
        return left / speed + 1;
    }
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;

    for (int i = 0; i < progresses.size(); i++) {
        int day = calcDay(progresses[i], speeds[i]);

        if (days.empty() || days.front() >= day) {
            days.push(day);
        } else {
            answer.push_back(days.size());
            while (!days.empty()) {
                days.pop();
            }
            days.push(day);
        }
    }
    answer.push_back(days.size());

    return answer;
}