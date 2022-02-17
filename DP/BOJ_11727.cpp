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
	dp[2] = 3;	// II, =, ��
	dp[3] = 5;  // III,I=,=I,I��,��I
	//dp[2] ���ʿ� I �߰�  III, I=,I��
	//dp[1] ���ʿ� = �߰�  =I
	//dp[1] ���ʿ� ���߰�  ��I

	//dp[4]�� ��� 11�̴�. (n-1)+2(n-2)
	//dp[3]���ʿ� I�߰�   IIII,II=,I=I,II��,I��I
	//dp[2]���ʿ� =�߰�   =II,==, =��
	//dp[2]���ʿ� ���߰�  ��II,��=,����


	//���� �ذ�
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007;
	}

	//��� ���
	cout << dp[n] << '\n';
}