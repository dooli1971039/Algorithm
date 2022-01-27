#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//입력
	int n, k,tmp;
	cin >> n >> k; //동전 종류, 만들려는 합

	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp); //동전의 가치가 오름차순으로 주어짐
	}

	//문제 해결
	int count = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (k == 0) break;

		if (k >= v[i]) {
			count += (k / v[i]); //몫은 저장
			k = k % v[i]; //나머지는 남겨둔다
		}
	}

	//결과 출력
	cout << count << '\n';
}