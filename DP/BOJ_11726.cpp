#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//입력
	int n; cin >> n;
	dp[1] = 1;  // I
	dp[2] = 2;	// II, =
	dp[3] = 3;  // III,I=,=I

	//dp[4]의 경우 5이다. (n-1)+(n-2)
	//dp[3]왼쪽에 I추가   IIII,II=,I=I
	//dp[2]왼쪽에 =추가   =II,==

	//dp[5]의 경우 8이다.
	//dp[4]왼쪽에 I추가   IIIII,III=,II=I,I=II,I==
	//dp[3]왼쪽에 =추가   =IIII,=II=,=I=I

	//문제 해결
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}

	//결과 출력
	cout << dp[n] << '\n';

}