#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	string str;
	getline(cin, str);

	//문제 해결
	int result = 0;
	string tmp = "";
	bool minus = false;

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || i == str.length()) { //부호를 입력 받았을 때
			if (minus) {//음수일때
				result -= stoi(tmp);
				tmp = ""; //임시 문자열 초기화
			}
			else {
				result += stoi(tmp);
				tmp = ""; //임시 문자열 초기화
			}
		}
		else {
			tmp += str[i];
		}

		//부호가 마이너스일때.
		if (str[i] == '-') {
			minus = true;
		}
	}

	//결과 해결
	cout << result << '\n';
}