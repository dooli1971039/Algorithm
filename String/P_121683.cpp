/* PCCP 모의고사 1회 1번
 * https://school.programmers.co.kr/learn/courses/15008/lessons/121683?language=cpp
 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(string input_string) {
    vector<int> position(26, -1); //-1로 초기화
    vector<bool> alone(26, false);

    bool flag = false;

    for (int i = 0; i < input_string.size(); i++) {
        char ch = input_string[i];

        if (position[ch - 'a'] == -1 || position[ch - 'a'] == i - 1) { // 새로 있거나 연결 된 경우
            position[ch - 'a'] = i;
        } else {
            alone[ch - 'a'] = true;
            position[ch - 'a'] = i;
            flag = true;
        }
    }

    if (!flag)
        return "N";

    string answer = "";
    for (int i = 0; i < 26; i++) {
        if (alone[i])
            answer += ('a' + i);
    }
    return answer;
}