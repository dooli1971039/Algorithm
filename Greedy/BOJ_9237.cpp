#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const int& a, const int& b) {
	if (a > b) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n;
	cin >> n;
	vector<int>time(n);
	for (int i = 0; i < n; i++) cin >> time[i];

	//���� �ذ�
	sort(time.begin(), time.end(), compare);

	for (int i = 0; i < n; i++) {
		time[i] += i; //�պκ� ��ĭ ä������
	}

	int mmax = time[0];
	for (int i = 1; i < n; i++) {
		mmax = max(mmax, time[i]);
	}

	//+2 �ϴ� ����: ù�� �ɴ� �� + ����� �ʴ� 
	cout <<  mmax+2 << '\n'; 
}