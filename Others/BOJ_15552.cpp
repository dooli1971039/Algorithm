#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int case_num;
	cin >> case_num; //입력

	for (int i = 0; i < case_num; i++) {
		int first, second;
		cin >> first >> second;
		cout << first + second << '\n';
	}

	return 0;
}