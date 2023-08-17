#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int n, l, r;
int arr[51][51];
int cnt; // 연합 개수

void makeUnion(vector<vector<int>> &visited) {
    cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // visited[i][j]가 0이 아니면 이미 연합에 속해있으므로, bfs를 돌릴 필요가 X
            if (visited[i][j]) {
                continue;
            }

            // visited[i][j]가 0이라는 뜻은, 자신부터 새로운 연합을 만들어야 한다는 의미
            queue<pair<int, int>> q;
            q.push({i, j});
            cnt++;
            visited[i][j] = cnt; // 몇번 연합인지 기록

            while (!q.empty()) {
                auto point = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = point.first + dr[i];
                    int nc = point.second + dc[i];

                    if (nr >= 1 && nc >= 1 && nr <= n && nc <= n && visited[nr][nc] == 0) {
                        int diff = abs(arr[nr][nc] - arr[point.first][point.second]);

                        if (diff >= l && diff <= r) {
                            q.push({nr, nc});
                            visited[nr][nc] = visited[point.first][point.second];
                        }
                    }
                }
            }
        }
    }
}

void changePeopleNum(vector<vector<int>> &visited) {
    vector<pair<int, int>> peopleSum(cnt + 1, {0, 0}); // 연합 별 {인구 수, 국가 수}

    // 연합의 인구수 구하기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            peopleSum[visited[i][j]].first += arr[i][j]; // 해당 연합에 전체 몇명의 인구가 포함되어있는지 체크
            peopleSum[visited[i][j]].second++; // 해당 연합에 포함된 국가 수 체크
        }
    }

    // 각 나라별로 인구수 세팅
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = peopleSum[visited[i][j]].first / peopleSum[visited[i][j]].second;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    int day = 0;
    while (true) {
        vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0)); // visited는 매번 초기화가 필요해서 인자로 넘겨줌
        makeUnion(visited);

        if (cnt == n * n) { // 연합 개수 == 국가 개수 => 서로 연합된 곳이 없음 (종료)
            break;
        }

        changePeopleNum(visited);
        day++;
    }
    cout << day;
}