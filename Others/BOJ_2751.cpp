#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	//정렬
	sort(arr.begin(), arr.end());

	//출력
	for (int i = 0; i < n;i++) cout << arr[i] << '\n';
}