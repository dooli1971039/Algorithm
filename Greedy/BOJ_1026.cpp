#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n,tmp;
	cin >> n;
	vector<int>v1; vector<int>v2;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v1.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}

	//���� �ذ�
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end()); 
	//�迭B�� ��迭 ���� ����� �Ǿ�������, ����..?

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = result + v1[i] * v2[n-i-1];
	}
	
	//��� ���
	cout << result << '\n';
}