#include <iostream>
#include <algorithm>
using namespace std;
int n,k,tmp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; //테스트 케이스
	
	for (int i = 0; i < n; i++) {
		//입력
		cin >> k;
		int ssum = 0;
		for (int j = 0; j < k; j++) {
			cin >> tmp;
			ssum += tmp;
		}

		//계산 및 출력
		if (ssum % k == 0) cout << 0 << '\n';
		else cout << 1 << '\n';
	}
}