#include <iostream>
#include <algorithm> //binary_search() : ���ĵ� ���¿��� ���
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n, m;
	cin >> n >> m;
	vector<string>v1(n); //�赵 ���� ���
	vector<string>result;
	for (int i = 0; i < n; i++) cin >> v1[i];
	
	//���� �ذ�
	sort(v1.begin(), v1.end());

	string mm;
	for (int i = 0; i < m; i++) {
		cin >> mm;
		if (binary_search(v1.begin(), v1.end(), mm)) result.push_back(mm);

	}
	sort(result.begin(), result.end());

	//��� ���
	cout << result.size() << '\n';
	for (string tmp : result) cout << tmp << '\n';
}
