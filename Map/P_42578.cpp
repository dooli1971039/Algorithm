#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> mp;
    for (int i = 0; i < clothes.size(); i++) {
        mp[clothes[i][1]]++;
    }

    int answer = 1;
    for (auto item : mp) {
        answer *= (item.second + 1);
    }

    return answer - 1; // 아무것도 선택하지 않는 경우 제외
}