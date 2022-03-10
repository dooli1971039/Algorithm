#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int day; cin >> day;
		vector<int>money(day);
		for (int j = 0; j < day; j++) cin >> money[j];
		
		//문제 해결 => 뒤에서부터 탐색 하자
		//구입 시점 이후에서 가장 비쌀 때를 미리 확인하고 삼
		//손해보게 파는것 보단 아예 안 사는게 나을 때도 있다
		long long result = 0; //int로 선언하면 틀린다.
		int k = day - 1;
		for (int j = day-2; j >= 0; j--) {
			if (money[k] > money[j]) result += money[k] - money[j];
			else k = j; // 이 경우에 money[k]가 가리키는 값이 더 커진다. (max값 찾는 과정)
		}
		
		//결과 출력
		cout << result << '\n';
	}
}