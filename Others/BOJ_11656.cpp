#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//�Է�
	string str;
	cin >> str;
	
	//���� �ذ�
	int n = str.length(); //���ڿ��� ����
	vector<string>v;
	
	for (int i = n; i >0; i--) {
		v.push_back(str.substr(n-i,i));
	}
	sort(v.begin(), v.end());

	//��� ���
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}