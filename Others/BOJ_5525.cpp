#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//50점만 받음...ㅠㅠ

string IOI(int n) {
	if (n == 1) return "IOI";
	else {
		string str = "IOI";
		for (int i = 0; i < n - 1; i++) {
			str += "OI";
		}
		return str;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;

	int count = 0;
	int pos = -1;
	string result = IOI(n);

	while (true) {
		pos = str.find(result, pos + 1);
		if (pos == -1) break;

		count++;
	}


	cout << count << '\n';

}