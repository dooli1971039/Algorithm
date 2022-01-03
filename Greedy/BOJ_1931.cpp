#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,a,b,cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vector<pair<int, int>>v;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ b,a }); //{끝나는 시간, 시작 시간}
	}

	sort(v.begin(), v.end()); //오름차순으로 정렬 (끝나는시간이 빠른 순서대로 정렬됨)

	b = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second < b) //시작하는 시간이 이전 것의 끝나는 시간보다 앞설 때
			continue;

		cnt++; //회의 개수 카운트
		b = v[i].first;
	}

	//결과 출력
	cout << cnt << '\n';
}