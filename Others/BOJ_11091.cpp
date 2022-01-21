#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	int n;
	cin >> n;
	cin.ignore(); //�Է� ���ۿ� �����ִ� ��� ������ �������ش�.

	for (int j = 0; j < n; j++) {
		//�Է�
		string str;
		getline(cin, str);

		//���� �ذ�
		for (int i = 0; i < str.size(); i++) {
			str[i] = tolower(str[i]);
		}

		int pos;
		string result = "";
		for (int i = 0; i < 26; i++) {
			pos = str.find(alphabet[i]);
			if (pos == -1) {
				result += alphabet[i];
			}
		}

		//��� ���
		if (result.length() == 0) {
			cout << "pangram\n";
		}
		else {
			cout <<"missing "<< result << '\n';
		}
	}	
}