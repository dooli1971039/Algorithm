#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	string str;
	getline(cin, str);

	//���� �ذ�
	int result = 0;
	string tmp = "";
	bool minus = false;

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || i == str.length()) { //��ȣ�� �Է� �޾��� ��
			if (minus) {//�����϶�
				result -= stoi(tmp);
				tmp = ""; //�ӽ� ���ڿ� �ʱ�ȭ
			}
			else {
				result += stoi(tmp);
				tmp = ""; //�ӽ� ���ڿ� �ʱ�ȭ
			}
		}
		else {
			tmp += str[i];
		}

		//��ȣ�� ���̳ʽ��϶�.
		if (str[i] == '-') {
			minus = true;
		}
	}

	//��� �ذ�
	cout << result << '\n';
}