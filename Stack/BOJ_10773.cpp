#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n,num;
	cin >> n;
	stack<int> ss;

	//���� �ذ�
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) ss.pop();
		else ss.push(num);
	}
	int ans = 0; 
	int len = ss.size();
	for (int i = 0; i < len; i++) {
		ans += ss.top();
		ss.pop();
	}

	//��� ���
	cout << ans;
}