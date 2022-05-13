#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

//bool compare(pair<int, int>a, pair<int, int>b) {
//	if (a.first == b.first) {
//		return a.second < b.second;
//	}
//	else {
//		return a.first < b.first;
//	}
//}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;	cin >> n;
	vector<pair<int,int>> arr;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}

	//정렬
	sort(arr.begin(), arr.end());

	//출력
	for (int i = 0; i < n; i++) {
		cout << arr[i].first <<' '<< arr[i].second << '\n';
	}
}