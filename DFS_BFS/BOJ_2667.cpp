#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int arr[25][25];
int used[25][25];
int n;

void dfs(int r, int c, int danziNum) {
    used[r][c] = danziNum; // 방문체크

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n && arr[nr][nc] == 1 && used[nr][nc] == 0) {
            dfs(nr, nc, danziNum);
        }
    }
}

int main() {
    cin >> n;

    vector<pair<int, int>> house;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            arr[i][j] = (tmp[j] - '0');
            if (arr[i][j] == 1) {
                house.push_back({i, j});
            }
        }
    }

    int danziNum = 0;
    for (int i = 0; i < house.size(); i++) {
        int r = house[i].first;
        int c = house[i].second;

        if (used[r][c] == 0) {
            danziNum++;
            dfs(r, c, danziNum);
        }
    }

    vector<int> danzi(danziNum + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            danzi[used[i][j]]++;
        }
    }
    danzi[0] = danziNum;
    sort(danzi.begin() + 1, danzi.end());

    for (auto num : danzi) {
        cout << num << '\n';
    }
}