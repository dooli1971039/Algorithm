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
	//�Է�
	int n;
	string str;
	cin >> n >> str;

	vector<int>num(n);
	for (int i = 0; i < n; i++)	cin >> num[i];

	double first,second;
	stack<double>s;

	for (int i = 0; i < str.size(); i++) {
		if ('A'<=str[i] && str[i]<='Z') {//�ش繮�ڰ� ���ĺ��϶�
			s.push((double)num[str[i]-'A']);
		}
		else {//�ش繮�ڰ� ��ȣ�϶�
			second = s.top(); s.pop();
			first = s.top(); s.pop();
			s.push(calculate(str[i], first, second));
		}
	}
	double result = s.top();
	printf("%.2f\n", result);
}