#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Ǻ���ġ �迭 �����α� - ���� �� 45������ �ذ�ȴٰ� �Ѵ�.
	int fib[46] = { 0, 1 };
	for (int i = 2; i < 46; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	//�Է�
	int n,tmp;
	cin >> n;
	vector<int>v;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	//���� �ذ�
	
	for (int i = 0; i < v.size(); i++) { //�׽�Ʈ ������ ���� ���
		vector<int>result;

		while (v[i]) {
			for (int j = sizeof(fib)/sizeof(*fib)-1; j >= 0; j--) {
				if (fib[j] > v[i]) continue;
				result.push_back(fib[j]);
				v[i] -= fib[j];
				if (v[i] <= 0) break;
			}
		}
		sort(result.begin(), result.end());
		
		for (int k = 0; k < result.size(); k++) {
			cout << result[k] << ' ';
		}
		cout << '\n';
	}

}