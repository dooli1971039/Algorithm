#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int day; cin >> day;
		vector<int>money(day);
		for (int j = 0; j < day; j++) cin >> money[j];
		
		//���� �ذ� => �ڿ������� Ž�� ����
		//���� ���� ���Ŀ��� ���� ��� ���� �̸� Ȯ���ϰ� ��
		//���غ��� �Ĵ°� ���� �ƿ� �� ��°� ���� ���� �ִ�
		long long result = 0; //int�� �����ϸ� Ʋ����.
		int k = day - 1;
		for (int j = day-2; j >= 0; j--) {
			if (money[k] > money[j]) result += money[k] - money[j];
			else k = j; // �� ��쿡 money[k]�� ����Ű�� ���� �� Ŀ����. (max�� ã�� ����)
		}
		
		//��� ���
		cout << result << '\n';
	}
}