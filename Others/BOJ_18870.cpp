#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//�̰� �ڵ� ���ذ� ���� �ϴµ�, �ٽ� �϶�� �ص� ���ϰڴ�.
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n, tmp;
	cin >> n;
	vector<pair<int,int>>v;
	vector<int>ans(n);

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back({tmp,i}); // {��,����}
	}

	sort(v.begin(), v.end()); //���� �������� ����
	
	int cnt = 0; //ī����?
	int num = v[0].first; //��
	ans[v[0].second] = 0; //����� ����

	for (int i = 1; i < n; i++) {
		if (num == v[i].first) {
			ans[v[i].second] = cnt;
		}
		else {
			cnt++;
			ans[v[i].second] = cnt;
			num = v[i].first;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}

}