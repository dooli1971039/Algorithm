#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;
	cin >> n;
	vector<int>km(n - 1);
	vector<int>won(n);

	for (int i = 0; i < n - 1; i++) cin >> km[i];
	for (int i = 0; i < n; i++) cin >> won[i];

	//문제 해결
	//long long이 아니라 int로 하면 부분점수만 얻는다.
	long long money = won[0];
	long long ans = 0;
	for (int i = 0; i < n-1; i++) {
		money = min(money,(long long) won[i]);
		ans += km[i] * money;
	}

	//결과 출력
	cout << ans << '\n';
}