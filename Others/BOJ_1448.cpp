#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n,tmp; 
	cin >> n; //���� ����
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	//���� �ذ�
	sort(v.begin(), v.end());
	int a, b, c; //a<=b<=c
	int result = 0;
	for (int i = n-1; i >= 2; i--) {
		c = v[i];
		b = v[i - 1];
		a = v[i - 2];
		if (c >= a + b) continue;
		else {
			result = a + b + c;
			cout << result << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';
}