#include <iostream>
#include <vector>
using namespace std;

// 결과는 long long이 나온다.
// bfs처럼 돌리면 queue에 중복 노드가 여러번 삽입될 수 있어 메모리 초과가 발생

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == n - 1 && j == n - 1) || dp[i][j] == 0)
                continue;

            int dist = arr[i][j];
            if (dist + i < n)
                dp[dist + i][j] += dp[i][j];
            if (dist + j < n)
                dp[i][dist + j] += dp[i][j];
        }
    }

    cout << dp[n - 1][n - 1];
}