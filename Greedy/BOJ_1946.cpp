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
		int num,a,b; cin >> num;
		vector<pair<int, int>>score;
		for (int j = 0; j < num; j++) {
			cin >> a >> b;
			score.push_back(make_pair(a, b));
		}

		//���� �ذ�
		sort(score.begin(), score.end()); //���� ������ ����

		int mmin = score[0].second;
		int count = 0;
		for (int j = 1; j < num; j++) {
			if (mmin <= score[j].second) count++;
			else mmin = score[j].second;
		}

		//��� ���
		cout << num-count << '\n';
	}
}