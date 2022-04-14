#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;
	cin >> n;
	queue<int> qq;

	//문제 해결
	for (int i = 1; i <= n; i++) qq.push(i);

	int type = 0;
	while (qq.size()!=1) { //1개 남으면 탈출
		if (type%2==0) { //맨 위의 카드 버림
			qq.pop();
		}
		else { //맨 위의 카드를 제일 아래로 옮김
			qq.push(qq.front());
			qq.pop();
		}
		type++;
	}
	
	//결과 출력
	cout << qq.front() << '\n';
}