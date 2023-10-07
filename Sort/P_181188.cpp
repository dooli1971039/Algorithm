#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int cmp(vector<int> &v1, vector<int> &v2) {
    if (v1[1] == v2[1])
        return v1[0] < v2[0];
    else
        return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);

    long long check = -1;
    for (int i = 0; i < targets.size(); i++) {
        if (check <= targets[i][0]) { // 양 끝은 포함이 안돼서 = 필요
            check = targets[i][1];    // 끝지점 까지 중에 하나는 걸림
            answer += 1;
        }
    }

    return answer;
}