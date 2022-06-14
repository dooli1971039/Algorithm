#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//이건 코드 이해가 가긴 하는데, 다시 하라고 해도 못하겠다.
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n, tmp;
	cin >> n;
	vector<pair<int,int>>v;
	vector<int>ans(n);

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back({tmp,i}); // {값,순서}
	}

	sort(v.begin(), v.end()); //값을 기준으로 정렬
	
	int cnt = 0; //카운팅?
	int num = v[0].first; //값
	ans[v[0].second] = 0; //결과를 저장

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