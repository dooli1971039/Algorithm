#include <iostream>
#include <algorithm> //binary_search() : 정렬된 상태에서 사용
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n, m;
	cin >> n >> m;
	vector<string>v1(n); //듣도 못한 사람
	vector<string>result;
	for (int i = 0; i < n; i++) cin >> v1[i];
	
	//문제 해결
	sort(v1.begin(), v1.end());

	string mm;
	for (int i = 0; i < m; i++) {
		cin >> mm;
		if (binary_search(v1.begin(), v1.end(), mm)) result.push_back(mm);

	}
	sort(result.begin(), result.end());

	//결과 출력
	cout << result.size() << '\n';
	for (string tmp : result) cout << tmp << '\n';
}
