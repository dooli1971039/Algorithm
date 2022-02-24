#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;
	cin >> n;

	//문제 해결
	string ss = to_string(n);
	vector<char>v;
	for (int i = 0; i < ss.size(); i++) v.push_back(ss[i]);
	sort(v.begin(),v.end());

	//결과 출력
	for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
}