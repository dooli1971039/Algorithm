#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sorting(string A,string B) {
	// 1. ���� ��
	if (A.length() != B.length()) return A.length() < B.length();

	// 2. ���� �� ���ϱ�
	int asum = 0, bsum = 0;
	for (int i = 0; i < A.length(); i++) {
		if ('0' <= A[i] && A[i] <= '9') asum += A[i] - '0';
		if ('0' <= B[i] && B[i]<= '9') bsum += B[i] - '0';
	}
	if (asum != bsum) return asum < bsum;

	// 3. ������ ��
	return A < B;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n; string tmp;
	cin >> n;
	vector<string>v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	//���� �ذ�
	sort(v.begin(), v.end(), sorting);

	//��� ���
	for (int i = 0; i < n; i++) cout << v[i] << '\n';

	
}