#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    int answer = 1;

    int end = routes[0][1];

    for (int i = 1; i < routes.size(); i++) {
        if (end < routes[i][0]) { // 안겹침
            answer++;
            end = routes[i][1];
        } else if (end > routes[i][1]) { // 포함되면 범위 줄이기
            end = routes[i][1];
        }
    }

    return answer;
}