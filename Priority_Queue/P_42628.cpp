#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    set<int> ss;

    int num = 0;
    for (auto cmd : operations) {
        num = stoi(cmd.substr(2));
        if (cmd[0] == 'I') {
            ss.insert(num);
        } else {
            if (ss.empty())
                continue;
            if (num < 0) { // 최솟값 삭제
                ss.erase(ss.begin());
            } else {
                ss.erase(--ss.end());
            }
        }
    }

    if (ss.empty())
        return {0, 0};
    else
        return {*(--ss.end()), *ss.begin()};
}