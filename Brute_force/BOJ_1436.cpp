#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;
	cin >> n;

	//문제 해결
	int num = 666;
	string tmp;
	while (n > 0) {
		tmp = to_string(num);
		if (tmp.find("666") != -1) {//66이 문자열에 포함되면
			n--;
		}
		num++;
	}

	cout << tmp << '\n';
}