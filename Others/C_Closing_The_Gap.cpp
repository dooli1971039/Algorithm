#include <iostream>
#include <algorithm>
using namespace std;
int n,k,tmp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; //�׽�Ʈ ���̽�
	
	for (int i = 0; i < n; i++) {
		//�Է�
		cin >> k;
		int ssum = 0;
		for (int j = 0; j < k; j++) {
			cin >> tmp;
			ssum += tmp;
		}

		//��� �� ���
		if (ssum % k == 0) cout << 0 << '\n';
		else cout << 1 << '\n';
	}
}