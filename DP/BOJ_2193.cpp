#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long dp[n + 1][2];
    dp[1][0] = 0; // 0으로 끝나는 1자리 이친수
    dp[1][1] = 1; // 1로 끝나는 1자리 이친수

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n][0] + dp[n][1];
}