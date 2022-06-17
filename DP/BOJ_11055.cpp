#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//이건 못 풀겠다....
//https://m.blog.naver.com/occidere/220793914361

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n; cin >> n;
	vector<int>v(n);
	vector<int>dp(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dp[i]=v[i];
	}

	//문제 해결

	//i번째 원소로 끝나는 부분 수열 중 값이 가장 큰것
	//왼쪽을 살펴보아야 함.
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			// 증가할 때 && 지금까지의 값 < 그 이전의 값+ 해당 위치 값
			if (v[j]<v[i] && dp[i]<dp[j]+v[i]) { 
				dp[i] = dp[j] + v[i];
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans<<'\n';
}