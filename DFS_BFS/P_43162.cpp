#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    queue<int> q;

    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        answer++;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < n; j++) {
                if (computers[node][j] && !visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    return answer;
}