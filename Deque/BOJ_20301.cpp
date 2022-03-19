#include <iostream>
#include <deque>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n, k, m;
	cin >> n >> k>> m;

	deque<int>dq;
	for (int i = 1; i <= n; i++) dq.push_back(i);


	//문제 해결
	int count = 0;
	bool check = true;
	while (!dq.empty()) {
		if (check) { //앞을 빼서 뒤에 넣는다.
			for (int i = 0; i < k - 1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cout << dq.front() << '\n';
			dq.pop_front();
		
		}else{ //뒤를 빼서 앞에 넣는다.
			for (int i = 0; i < k - 1; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cout << dq.back() << '\n';
			dq.pop_back();
		}
		count++;
		if (count == m) {
			check = !check;
			count = 0;
		}
	}

}