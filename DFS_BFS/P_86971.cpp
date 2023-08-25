#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int divideTowerAndCalcNum(vector<int> arr[], int n) {
    vector<int> visit(n + 1, -1);

    queue<int> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[i] != -1)
            continue; // 이미 방문함

        q.push(i);
        visit[i] = ++cnt; // 1또는 2의 값을 갖게 된다.

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nxt : arr[node]) {
                if (visit[nxt] != -1)
                    continue; // 이미 방문함

                q.push(nxt);
                visit[nxt] = cnt;
            }
        }
    }

    int tower1 = count(visit.begin(), visit.end(), 1);
    int tower2 = count(visit.begin(), visit.end(), 2);

    return abs(tower1 - tower2);
}

int solution(int n, vector<vector<int>> wires) {
    int diff = 1000;

    for (int i = 0; i < n; i++) { // 몇번째 wire를 끊는지 결정

        vector<int> arr[n + 1];
        for (int j = 0; j < wires.size(); j++) { // 간선의 개수만큼만 or n-1
            if (i == j)
                continue;

            arr[wires[j][0]].push_back(wires[j][1]);
            arr[wires[j][1]].push_back(wires[j][0]);
        }
        // 계산
        diff = min(diff, divideTowerAndCalcNum(arr, n));
    }

    return diff;
}