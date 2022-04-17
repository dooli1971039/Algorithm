#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkVPS(string tmp) {
	stack<char>s;

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '(') {
			s.push('(');
		}
		else if (tmp[i] == '[') {
			s.push('[');
		}
		else if (tmp[i] == ')') {
			if (s.empty()) return false;
			else if (s.top() != '(') return false;
			else s.pop();
		}
		else if (tmp[i] == ']') {
			if (s.empty()) return false;
			else if (s.top() != '[') return false;
			else s.pop();
		}
	}
	if (s.empty()) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string tmp;
	while (true) {
		getline(cin,tmp); //공백이 있든 없든 한줄 입력 받음
		if (tmp == ".") break;

		string result = checkVPS(tmp) ? "yes" : "no";
		cout << result << '\n';
	}
}