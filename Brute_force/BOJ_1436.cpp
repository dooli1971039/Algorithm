#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n;
	cin >> n;

	//���� �ذ�
	int num = 666;
	string tmp;
	while (n > 0) {
		tmp = to_string(num);
		if (tmp.find("666") != -1) {//66�� ���ڿ��� ���ԵǸ�
			n--;
		}
		num++;
	}

	cout << tmp << '\n';
}