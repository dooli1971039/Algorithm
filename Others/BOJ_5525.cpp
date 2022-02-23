#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n, m; string str;
	cin >> n >> m >> str;

	//���� �ذ�
	int ans = 0;
	for (int i = 0; i < m; i++) {
		
		int k = 0; //IOI�� ����
		if (str[i] == 'O') continue;

		while (str[i + 1] == 'O' && str[i + 2] == 'I') {
			k++;

			if (k == n) {
				ans++;
				k--; //���������� +2��ŭ �̵����ٵ� �̶� k���� �ٲ��� �ʰ� �ϳ� ����
			}
			i += 2; //�ε��� �پ� �ѱ�
		}
	}

	//��� ���
	cout << ans << '\n';

}