#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//�Է�
	int n, k,tmp;
	cin >> n >> k; //���� ����, ������� ��

	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp); //������ ��ġ�� ������������ �־���
	}

	//���� �ذ�
	int count = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (k == 0) break;

		if (k >= v[i]) {
			count += (k / v[i]); //���� ����
			k = k % v[i]; //�������� ���ܵд�
		}
	}

	//��� ���
	cout << count << '\n';
}