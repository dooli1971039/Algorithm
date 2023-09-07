#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool compare(string a, string b) { return a + b > b + a; }

string solution(vector<int> numbers) {
    vector<string> numList;
    for (int num : numbers) {
        numList.push_back(to_string(num));
    }

    sort(numList.begin(), numList.end(), compare);
    if (numList[0] == "0")
        return "0"; // 0000 인 경우 0으로 출력

    string answer = "";
    for (string str : numList) {
        answer += str;
    }

    return answer;
}