#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sorting(string A,string B) {
	// 1. 길이 비교
	if (A.length() != B.length()) return A.length() < B.length();

	// 2. 숫자 합 구하기
	int asum = 0, bsum = 0;
	for (int i = 0; i < A.length(); i++) {
		if ('0' <= A[i] && A[i] <= '9') asum += A[i] - '0';
		if ('0' <= B[i] && B[i]<= '9') bsum += B[i] - '0';
	}
	if (asum != bsum) return asum < bsum;

	// 3. 사전순 비교
	return A < B;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n; string tmp;
	cin >> n;
	vector<string>v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	//문제 해결
	sort(v.begin(), v.end(), sorting);

	//결과 출력
	for (int i = 0; i < n; i++) cout << v[i] << '\n';

	
}