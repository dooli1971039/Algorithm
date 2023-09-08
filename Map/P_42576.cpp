#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> mp;
    for (auto str : completion) {
        mp[str]++;
    }

    for (auto name : participant) {
        if (mp[name] == 0) {
            return name;
        }
        mp[name]--;
    }

    return "";
}