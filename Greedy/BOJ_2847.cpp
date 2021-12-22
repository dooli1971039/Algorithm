#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, num, cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	cnt = 0;
	for (int i = n - 1; i > 0; i--) {
		if (v[i] > v[i - 1]) continue;

		num=v[i - 1] - v[i] + 1;
		v[i - 1] -= num;
		cnt += num;
	}
	
	cout << cnt << '\n';
}