#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int arr[5][5];
set<int>ss;

//자리 이동
int xx[4] = { 1, -1, 0, 0 };
int yy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int count, int num) {
	if (count == 5) {
		ss.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int px = x + xx[i];
		int py = y + yy[i];

		if (px < 0 || py < 0 || px>=5 || py>=5 ) continue;
		dfs(px, py, count + 1, num * 10 + arr[px][py]);
	}
}

int main() {
	//입력
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) 
			cin >> arr[i][j];

	//문제 해결
	for (int i = 0; i < 5; i++) //행 (y좌표)
		for (int j = 0; j < 5; j++) //열 (x좌표)
			dfs(j,i,0,arr[j][i]);
	
	//결과 출력
	cout << ss.size() << '\n';
}