#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	string str="";
	getline(cin, str); //������ �ִ� ������ �Է¹ޱ� ����

	int n1, n2, n3, n4;

	n1 = str.find('U');
	n2 = str.find('C',n1);
	n3 = str.find('P',n2);
	n4 = str.find('C',n3);
	
	if (n1 == -1 || n2 == -1 || n3 == -1 || n4 == -1) {
		cout << "I hate UCPC";
	}
	else {
		cout << "I love UCPC";
	}

}