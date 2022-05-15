#include <iostream>
using namespace std;

int dp[21][21][21] = { 0, };

int w_recur(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) return w_recur(20, 20, 20);

	else if (dp[a][b][c] != 0) return dp[a][b][c];

	else if (a < b && b < c)
		dp[a][b][c] = w_recur(a, b, c - 1) + w_recur(a, b - 1, c - 1) - w_recur(a, b - 1, c);
	else
		dp[a][b][c] = w_recur(a-1, b, c) + w_recur(a-1, b - 1, c) + w_recur(a - 1, b , c-1) - w_recur(a-1, b - 1, c-1);

	return dp[a][b][c];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int a, b, c;

	//문제 해결
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		int result = w_recur(a,b,c);

		//결과 출력
		cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
	}
}