#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    vector<int> arr;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (isspace(s[i])) {
            arr.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    arr.push_back(stoi(tmp));
    sort(arr.begin(), arr.end());

    string answer = to_string(arr[0]);
    answer += ' ';
    answer += to_string(arr[arr.size() - 1]);
    return answer;
}