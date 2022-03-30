#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10001] = { 0, };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n,k;
	cin >> n>>k; //n���� ����, k���� ������ �Ѵ�.
	vector<int>money(n+1);
	for (int i = 1; i <= n; i++) cin >> money[i];

	//���� �ذ�
	for (int i = 1; i <= k; i++) dp[i] = 10001; //�ּڰ��� ���ϱ� ����

	for (int i = 1; i <= n; i++) { // money[i] ������ ������
		for (int j = money[i]; j <= k; j++) { // �ּڰ��� ���� �� ������ ����
			dp[j] = min(dp[j], dp[j - money[i]] + 1);
		}
	}

	if (dp[k] == 10001) cout << -1 << '\n';
	else cout << dp[k] << '\n';
}