/* PCCP 모의고사 1회 3번
 * https://school.programmers.co.kr/learn/courses/15008/lessons/121685
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string calcBean(int level, int num) { // 몇레벨의 몇번째 개체
    if (level == 1) {
        return "Rr";
    } else if (level == 2) {
        if (num == 1)
            return "RR";
        else if (num == 4)
            return "rr";
        else
            return "Rr";
    }

    int next_num = (num % 4) ? num / 4 + 1 : num / 4;
    string parent = calcBean(level - 1, next_num);

    if (parent == "Rr") {
        int next = (num % 4) ? num % 4 : 4;
        return calcBean(2, next);
    } else
        return parent;
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for (int i = 0; i < queries.size(); i++) {
        string result = calcBean(queries[i][0], queries[i][1]);
        answer.push_back(result);
    }
    return answer;
}