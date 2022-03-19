#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;
	cin >> n;
	
	//문제 해결
	/*
	dp[1]=상근 1
	dp[2]=창영 1 1
	dp[3]=상근 3
	dp[4]=창영 3 1 / 1 1 1 1
	dp[5]=상근 3 1 1 / 1 3 1
	dp[6]=창영 3 3
	*/
	if (n % 2 == 0) cout << "CY\n";
	else cout << "SK\n";
}