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
	vector<int>v1; vector<int>v2;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v1.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}

	//문제 해결
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end()); 
	//배열B는 재배열 하지 말라고 되어있지만, 굳이..?

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = result + v1[i] * v2[n-i-1];
	}
	
	//결과 출력
	cout << result << '\n';
}