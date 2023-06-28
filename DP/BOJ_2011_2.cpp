#include <iostream>
#define MOD 1000000

using namespace std;

int calc_dp(string str, int n) {
    if (str[0] == '0') {
        return 0;
    }

    int dp[n + 1] = {
        0,
    };
    dp[0] = dp[1] = 1;
    // 기준이 되는 곳은 i-1
    for (int i = 2; i <= n; i++) {
        if (str[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }

        int num = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
        if (num >= 10 && num <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD; // 저 부분이 i-1이 아니라 i여야 한다.
        }
    }

    return dp[n];
}

int main() {
    string str;
    cin >> str;
    int n = str.size();
    cout << calc_dp(str, n);
}