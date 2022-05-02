#include <iostream>
using namespace std;

int factorial(int num) {
	if (num <= 1) return 1; //종료조건
	
	return factorial(num - 1) * num;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;
	cin >> n;

	//결과 출력
	cout << factorial(n) << '\n';
}