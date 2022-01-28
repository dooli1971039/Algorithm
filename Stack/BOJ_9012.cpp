#include <iostream>
#include <stack>
using namespace std;

bool checkVPS(string tmp) {
	stack<char>s;

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '(') {
			s.push('(');
		}
		else if(tmp[i]==')') {
			if (s.empty()) return false;
			else s.pop();
		}
	}
	if (s.empty()) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int testcase;
	cin >> testcase;

	//문제 해결
	for (int i = 0; i < testcase; i++) {
		string tmp;
		cin >> tmp;
		string result = checkVPS(tmp) ? "YES" : "NO";
		cout << result << '\n';		
	}
}