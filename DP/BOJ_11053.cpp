#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, tmp;
	cin >> n;

	vector<int>v(n);
	vector<int>dp(n,1); //i번째 값이 가지는 가장 긴 증가하는 부분수열의 길이 (값이 적어도 1이상임)

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) { //자기보다 앞쪽을 탐색
			if (v[i] > v[j]) { //앞쪽에 있는게 자기꺼보다 작을 때
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		ans = max(ans, dp[i]);
	}

	//n=1일때
	if (n == 1) cout << 1<< '\n';
	else cout << ans << '\n';

}