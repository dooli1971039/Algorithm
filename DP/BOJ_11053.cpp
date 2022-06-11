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
	vector<int>dp(n,1); //i��° ���� ������ ���� �� �����ϴ� �κм����� ���� (���� ��� 1�̻���)

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) { //�ڱ⺸�� ������ Ž��
			if (v[i] > v[j]) { //���ʿ� �ִ°� �ڱⲨ���� ���� ��
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		ans = max(ans, dp[i]);
	}

	//n=1�϶�
	if (n == 1) cout << 1<< '\n';
	else cout << ans << '\n';

}