#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, num, mmin;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; //팀의 개수
	vector<int>v;
	for (int i = 0; i < 2*n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end()); //정렬

	mmin = 1e9;
	for (int i = 0; i < n; i++) {
		num = v[i] + v[2 * n - i - 1];
		mmin = min(mmin, num);
	}

	cout << mmin << '\n';	
}