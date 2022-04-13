#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n,tmp;
	cin >> n;
	stack<int> ss;
	string str;

	//문제 해결
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> tmp;
			ss.push(tmp);
		}
		else if (str == "pop") {
			if (ss.empty()) cout << -1 << '\n';
			else {
				cout << ss.top() << '\n';
				ss.pop();
			}
		}
		else if (str == "size") {
			cout << ss.size() << '\n';
		}
		else if (str == "empty") {
			if (ss.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (str == "top") {
			if (ss.empty()) cout << -1 << '\n';
			else {
				cout << ss.top() << '\n';
			}
		}
	}
}