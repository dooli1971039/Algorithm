#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n + 1][2] = {
        0,
    };
    for (int i = 1; i <= n; i++)
        cin >> arr[i][0] >> arr[i][1];

    int dp[n + 2] = {
        0,
    }; // 처음꺼 계산을 위해 n+2

    // 뒤에서부터 계산
    for (int i = n; i >= 1; i--) {
        int nextDay = arr[i][0] + i;
        if (nextDay > n + 1) { // 기간 넘어가면 바로 전날꺼
            dp[i] = dp[i + 1];
            continue;
        }
        dp[i] = max(dp[i + 1], arr[i][1] + dp[nextDay]);
    }

    cout << dp[1];
}