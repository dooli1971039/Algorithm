#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int num; cin >> num; //글자수
		int w = 0, b = 0;
		string input, base;
		cin >> input >> base;
		
		for (int i = 0; i < num; i++) {
			if (input[i] == base[i]) continue;
			else {//글자가 다를 때
				if (input[i] == 'B') b++;
				else w++;				
			}
		}

		//문제 해결 및 결과 출력
		if (w > b) cout << w << '\n';
		else cout << b << '\n';
	}
}