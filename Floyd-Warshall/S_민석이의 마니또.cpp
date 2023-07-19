#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1e5 + 1
using namespace std;

void floydWarshall(vector<vector<int>> &arr, int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // k 지점을 지나는 것이 더 저렴할 경우 업데이트
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

int findMinCostCycle(vector<vector<int>> &arr, vector<pair<int, int>> &friends) {
    int mmin = INF;

    for (int i = 0; i < friends.size(); i++) {
        int x = friends[i].first;
        int y = friends[i].second;

        if (x == y) {
            mmin = min(arr[x][y], mmin);
        } else {
            mmin = min(arr[x][y] + arr[y][x], mmin);
        }
    }

    if (mmin == INF)
        return -1;
    return mmin;
}

int solution() {
    int n, m;
    cin >> n >> m; // 학생 수, 마니또 관계의 수

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, INF));

    int x, y, c;
    vector<pair<int, int>> friends(m);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> arr[x][y];
        friends[i] = {x, y};
    }

    floydWarshall(arr, n);
    return findMinCostCycle(arr, friends);
}

int main() {
    int testCase;
    cin >> testCase;

    for (int i = 1; i <= testCase; i++) {
        cout << "#" << i << " " << solution() << '\n';
    }
    return 0;
}