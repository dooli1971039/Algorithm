#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	//문제 해결
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += v[j];
		}
	}
	
	//결과 출력
	cout << sum << '\n';
}