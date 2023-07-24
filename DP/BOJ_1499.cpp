#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n + 1][3];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }

    int dp[n + 1][3]; // 빨, 초, 파
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0]; // i번째 집을 칠할 때까지의 최소값 (i번째는 빨강)
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1]; // i번째 집을 칠할 때까지의 최소값 (i번째는 초록)
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2]; // i번째 집을 칠할 때까지의 최소값 (i번째는 파랑)
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}