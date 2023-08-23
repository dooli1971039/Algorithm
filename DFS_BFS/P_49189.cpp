#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> arr[n + 1];
    for (int i = 0; i < edge.size(); i++) {
        arr[edge[i][0]].push_back(edge[i][1]);
        arr[edge[i][1]].push_back(edge[i][0]);
    }

    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto nxt : arr[node]) {
            if (vis[nxt])
                continue;

            q.push(nxt);
            vis[nxt] = vis[node] + 1;
        }
    }

    int far = *max_element(vis.begin(), vis.end());
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == far)
            answer++;
    }
    return answer;
}