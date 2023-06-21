#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 상, 우, 하, 좌
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int n, m;
int c, r, dir;

bool check_blank(vector<vector<int>> &arr) {
    for (int i = 0; i < 4; i++) {
        int nc = c + dc[i];
        int nr = r + dr[i];

        if (0 <= nc && nc < m && 0 <= nr && nr < n) {
            if (arr[nr][nc] == 0) { // 청소 안 된 빈칸이 있으면
                return true;
            }
        }
    }
    return false;
}

int clear(vector<vector<int>> &arr) {
    int cnt = 0;

    while (true) {
        if (arr[r][c] == 0) {
            arr[r][c] = -1; // 청소
            cnt++;
        }

        // 상하좌우 탐색 -> 빈칸이 있나?
        if (check_blank(arr)) {
            // 반시계 방향으로 90도 회전
            dir = (dir + 4 - 1) % 4;

            // 바라보는 방향이 청소되지 않았으면 한칸 전진
            int nc = c + dc[dir];
            int nr = r + dr[dir];
            if (arr[nr][nc] == 0) {
                c = nc;
                r = nr;
            }
        } else {
            // 바라보는 방향을 유지한 채 한칸 후진 가능 시 한칸 후진 -> 반복문 처음으로
            int nc = c - 1 * dc[dir];
            int nr = r - 1 * dr[dir];
            if (0 <= nc && nc < m && 0 <= nr && nr < n && arr[nr][nc] != 1) { // 후진 가능
                r = nr;
                c = nc;
            } else {
                return cnt;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));

    cin >> r >> c >> dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << clear(arr);
}