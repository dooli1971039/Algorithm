#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//�Է�
	int n; cin >> n;
	dp[1] = 1;  // I
	dp[2] = 2;	// II, =
	dp[3] = 3;  // III,I=,=I

	//dp[4]�� ��� 5�̴�. (n-1)+(n-2)
	//dp[3]���ʿ� I�߰�   IIII,II=,I=I
	//dp[2]���ʿ� =�߰�   =II,==

	//dp[5]�� ��� 8�̴�.
	//dp[4]���ʿ� I�߰�   IIIII,III=,II=I,I=II,I==
	//dp[3]���ʿ� =�߰�   =IIII,=II=,=I=I

	//���� �ذ�
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}

	//��� ���
	cout << dp[n] << '\n';

}