#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, past_max, cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	a = 0, past_max = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < a)
			cnt++;
		else {
			past_max = max(past_max, cnt);
			cnt = 0;
			a = v[i];
		}
	}
	past_max = max(past_max, cnt); //마지막에 한번 더 체크해줘야 한다.
	cout << past_max << '\n';
}