#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n, m;
	cin >> n >> m;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];


	//문제 해결
	int sum = 0, mmax = 0;
	for (int i = 0; i <n-2; i++) {
		for (int j = i +1; j <n-1; j++) {
			for (int k = j+1; k <n; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= m) {
					mmax = max(mmax, sum);
				}
			}
		}
	}
	
	//결과 출력
	cout << mmax << '\n';
}