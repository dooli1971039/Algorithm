#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        int st = commands[i][0] - 1;
        int ed = commands[i][1];
        int k = commands[i][2] - 1;

        vector<int> tmp;
        for (int i = st; i < ed; i++) {
            tmp.push_back(array[i]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k]);
    }

    return answer;
}