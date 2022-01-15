#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//피보나치 배열 만들어두기 - 대충 한 45정도면 해결된다고 한다.
	int fib[46] = { 0, 1 };
	for (int i = 2; i < 46; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	//입력
	int n,tmp;
	cin >> n;
	vector<int>v;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	//문제 해결
	
	for (int i = 0; i < v.size(); i++) { //테스트 데이터 별로 계산
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