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
	vector<int>arr(n);

	//문제 해결
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		arr.insert(arr.begin() + tmp, i);
	}

	//결과 출력
	for (int i = n - 1; i >= 0; i--) cout << arr[i] << ' ';
}