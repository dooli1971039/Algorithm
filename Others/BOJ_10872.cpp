#include <iostream>
using namespace std;

int factorial(int num) {
	if (num <= 1) return 1; //��������
	
	return factorial(num - 1) * num;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n;
	cin >> n;

	//��� ���
	cout << factorial(n) << '\n';
}