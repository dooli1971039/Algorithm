#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int returnScore(int n) {
    if (n == 0 || n == 1)
        return 6;
    else
        return 6 - n + 1;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2, 0);

    for (int i = 0; i < 6; i++) {
        if (lottos[i] == 0) {
            answer[0]++;
            continue;
        }

        int num = count(win_nums.begin(), win_nums.end(), lottos[i]);
        answer[0] += num;
        answer[1] += num;
    }

    answer[0] = returnScore(answer[0]);
    answer[1] = returnScore(answer[1]);

    return answer;
}