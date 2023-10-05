#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tc(n, 0);
    for (int i = 0; i < n; i++)
        cin >> tc[i];
    int maxx = *max_element(tc.begin(), tc.end());

    int dp[maxx + 1][4] = {
        0,
    };

    dp[1][1] = dp[2][1] = dp[3][1] = 1; // +1
    dp[2][2] = dp[3][2] = 1;            // +2
    dp[3][3] = 1;                       //+3

    for (int i = 4; i <= maxx; i++) {
        // 모든 수를 오름차순으로 한다고 했을 때
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    for (int i = 0; i < n; i++) {
        int num = tc[i];

        cout << dp[num][1] + dp[num][2] + dp[num][3] << '\n';
    }
}