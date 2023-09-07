#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int answer = n - lost.size();
    for (int i = 0; i < lost.size(); i++) {
        int num = lost[i];
        for (int j = 0; j < reserve.size(); j++) {
            if (num == reserve[j]) {
                reserve[j] = -1;
                lost[i] = -1;
                answer++;
                break;
            }
        }
    }

    for (int i = 0; i < lost.size(); i++) {
        int num = lost[i];
        for (int j = 0; j < reserve.size(); j++) {
            if (num - 1 == reserve[j] || num + 1 == reserve[j]) {
                reserve[j] = -1;
                lost[i] = -1;
                answer++;
                break;
            }
        }
    }
    return answer;
}