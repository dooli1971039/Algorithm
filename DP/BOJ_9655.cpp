#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n;
	cin >> n;
	
	//���� �ذ�
	/*
	dp[1]=��� 1
	dp[2]=â�� 1 1
	dp[3]=��� 3
	dp[4]=â�� 3 1 / 1 1 1 1
	dp[5]=��� 3 1 1 / 1 3 1
	dp[6]=â�� 3 3
	*/
	if (n % 2 == 0) cout << "CY\n";
	else cout << "SK\n";
}