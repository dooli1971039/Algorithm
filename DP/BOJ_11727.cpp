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
	dp[2] = 3;	// II, =, ㅁ
	dp[3] = 5;  // III,I=,=I,Iㅁ,ㅁI
	//dp[2] 왼쪽에 I 추가  III, I=,Iㅁ
	//dp[1] 왼쪽에 = 추가  =I
	//dp[1] 왼쪽에 ㅁ추가  ㅁI

	//dp[4]의 경우 11이다. (n-1)+2(n-2)
	//dp[3]왼쪽에 I추가   IIII,II=,I=I,IIㅁ,IㅁI
	//dp[2]왼쪽에 =추가   =II,==, =ㅁ
	//dp[2]왼쪽에 ㅁ추가  ㅁII,ㅁ=,ㅁㅁ


	//문제 해결
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007;
	}

	//결과 출력
	cout << dp[n] << '\n';
}