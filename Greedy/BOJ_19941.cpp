#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n, k;
	cin >> n >> k;
	vector<char>arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	//문제 해결
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) {
				if (j<0 || j>n - 1) continue;
				
				if (arr[j] == 'H') {
					count++;
					arr[j] = 'Q';
					break;
				}
			}
		}
	}

	cout << count << '\n';
}