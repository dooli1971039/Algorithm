#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//�̰� �� Ǯ�ڴ�....
//https://m.blog.naver.com/occidere/220793914361

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n; cin >> n;
	vector<int>v(n);
	vector<int>dp(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dp[i]=v[i];
	}

	//���� �ذ�

	//i��° ���ҷ� ������ �κ� ���� �� ���� ���� ū��
	//������ ���캸�ƾ� ��.
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			// ������ �� && ���ݱ����� �� < �� ������ ��+ �ش� ��ġ ��
			if (v[j]<v[i] && dp[i]<dp[j]+v[i]) { 
				dp[i] = dp[j] + v[i];
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans<<'\n';
}