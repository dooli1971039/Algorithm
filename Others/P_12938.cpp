#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    int num = s / n;
    if (num == 0)
        return {-1};

    vector<int> answer(n, num);

    for (int i = 0; i < s % n; i++) {
        answer[i]++;
    }
    sort(answer.begin(), answer.end());

    return answer;
}