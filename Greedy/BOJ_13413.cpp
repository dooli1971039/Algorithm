#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int num; cin >> num; //���ڼ�
		int w = 0, b = 0;
		string input, base;
		cin >> input >> base;
		
		for (int i = 0; i < num; i++) {
			if (input[i] == base[i]) continue;
			else {//���ڰ� �ٸ� ��
				if (input[i] == 'B') b++;
				else w++;				
			}
		}

		//���� �ذ� �� ��� ���
		if (w > b) cout << w << '\n';
		else cout << b << '\n';
	}
}