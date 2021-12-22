#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,a,b,cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vector<pair<int, int>>v;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ b,a }); //{������ �ð�, ���� �ð�}
	}

	sort(v.begin(), v.end()); //������������ ����

	b = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second < b) //�����ϴ� �ð��� ���� ���� ������ �ð����� �ռ� ��
			continue;

		cnt++;
		b = v[i].first;
	}

	cout << cnt << '\n';

}