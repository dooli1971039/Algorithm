#include <string>
#include <vector>

using namespace std;

int answer = 0; // 개수
int globalTarget;
vector<bool> plusMinus;

int calcResult(vector<int> &numbers) {
    int ssum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (plusMinus[i]) {
            ssum += numbers[i];
        } else {
            ssum -= numbers[i];
        }
    }
    return ssum;
}

void backtracking(int idx, vector<int> &numbers, int target) {
    if (idx == numbers.size()) {
        if (target == calcResult(numbers))
            answer++;
        return;
    }

    plusMinus[idx] = false;
    backtracking(idx + 1, numbers, target);

    plusMinus[idx] = true;
    backtracking(idx + 1, numbers, target);
}

int solution(vector<int> numbers, int target) {
    plusMinus.assign(numbers.size(), false);
    backtracking(0, numbers, target);

    return answer;
}