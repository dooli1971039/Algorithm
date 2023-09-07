#include <string>
#include <vector>

using namespace std;

int dungeonNum;
vector<vector<int>> playOrder;
vector<int> order;
vector<bool> used;

void backtracking(int cnt) {
    if (cnt == dungeonNum) {
        playOrder.push_back(order);
        return;
    }

    for (int i = 0; i < dungeonNum; i++) {
        if (!used[i]) {
            used[i] = true;
            order[cnt] = i;
            backtracking(cnt + 1);
            used[i] = false;
        }
    }
}

int calcStatus(int idx, int k, vector<vector<int>> &dungeons) {
    vector<int> ord = playOrder[idx]; // 순서

    int cnt = 0;
    while (cnt < ord.size()) {
        int dungeonIdx = ord[cnt];
        if (k >= dungeons[dungeonIdx][0]) {
            k -= dungeons[dungeonIdx][1];
            cnt++;
        } else {
            break;
        }
    }

    return cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    dungeonNum = dungeons.size();
    order.assign(dungeonNum, -1);
    used.assign(dungeonNum, false);
    backtracking(0);

    int answer = -1;
    for (int i = 0; i < playOrder.size(); i++) {
        answer = max(answer, calcStatus(i, k, dungeons));
    }
    return answer;
}