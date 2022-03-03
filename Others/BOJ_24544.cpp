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
	vector<int>v(n);
	for(int i=0;i<n;i++) cin>>v[i];

	//문제 해결
	int tot=0,ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (!tmp) ans += v[i];
		tot += v[i];
	}

	cout << tot << '\n' << ans<<'\n';
}