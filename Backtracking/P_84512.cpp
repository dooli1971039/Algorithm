#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<string> strSet;
vector<int> result(5, -1);
string vowel = "AEIOU";

void backtracking(int cnt, int k) {
    if (cnt == k) {
        string tmp = "";
        for (int i = 0; i < cnt; i++) {
            tmp += vowel[result[i]];
        }
        strSet.insert(tmp);
        return;
    }

    for (int i = 0; i < 5; i++) {
        result[cnt] = i;
        backtracking(cnt + 1, k);
    }
}

int solution(string word) {
    int answer = 1;

    for (int i = 1; i <= 5; i++) {
        backtracking(0, i);
    }

    for (auto str : strSet) {
        if (str == word) {
            break;
        }
        answer++;
    }

    return answer;
}