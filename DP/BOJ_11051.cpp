#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//이항계수
////nCk = (n-1)Ck + (n-1)C(k-1)
////nCk = nC(n-k)
////nC0 = nCn =1
//int binomial(int n, int k) {
//	if (k == 0 || n == k) return 1;
//	else return binomial(n - 1, k) + binomial(n - 1, k - 1);
//}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n, k;
	cin >> n >> k;
	vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
	

	//문제 해결
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%10007;
		}
	}

	//결과 출력
	cout << dp[n][k] << '\n';
}