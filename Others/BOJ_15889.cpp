#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n,tmp;
	cin >> n;
	vector<int>v;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	int len = 0, max_len = 0;
	for (int i = 1; i < n; i++) {
		cin >> len; //사거리
		
		if (max_len < v[i - 1] + len) {
			max_len = v[i - 1] + len;
		}
		if (max_len < v[i]) {
			cout << "엄마 나 전역 늦어질 것 같아" << '\n';
			return 0;
		}
	}

	cout << "권병장님, 중대장님이 찾으십니다" << '\n';
}