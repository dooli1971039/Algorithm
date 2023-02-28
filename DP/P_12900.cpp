#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1000000007;
int solution(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1; // I
    dp[2] = 2; // II, =
    dp[3] = 3; // III,I=,=I

    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n];
}

int main() {
    vector<int> arr = {9, 15, 17, 20, 34, 59, 100, 123, 548, 3456, 9000, 10007, 30210, 50000, 59999, 60000};
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " " << solution(arr[i]) << "\n";
    }
}