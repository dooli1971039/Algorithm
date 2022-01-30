#include <iostream>
#include <stack>
#include <vector>
using namespace std;

double calculate(char ch,double first,double second) {
	if (ch == '+') return first + second;
	if (ch == '-') return first - second;
	if (ch == '*') return first * second;
	if (ch == '/') return first / second;
}

int main() {
	//입력
	int n;
	string str;
	cin >> n >> str;

	vector<int>num(n);
	for (int i = 0; i < n; i++)	cin >> num[i];

	double first,second;
	stack<double>s;

	for (int i = 0; i < str.size(); i++) {
		if ('A'<=str[i] && str[i]<='Z') {//해당문자가 알파벳일때
			s.push((double)num[str[i]-'A']);
		}
		else {//해당문자가 기호일때
			second = s.top(); s.pop();
			first = s.top(); s.pop();
			s.push(calculate(str[i], first, second));
		}
	}
	double result = s.top();
	printf("%.2f\n", result);
}