#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//입력
	string str;
	cin >> str;
	
	//문제 해결
	int n = str.length(); //문자열의 길이
	vector<string>v;
	
	for (int i = n; i >0; i--) {
		v.push_back(str.substr(n-i,i));
	}
	sort(v.begin(), v.end());

	//결과 출력
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}