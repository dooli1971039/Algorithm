#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check_win(char base, char fr) { 
	if (base == 'S') {//가위
		if (fr == 'S') return 1; //비김
		if (fr == 'P') return 2;
		if (fr == 'R') return 0;
	}
	if (base == 'P') {//보
		if (fr == 'S') return 0;
		if (fr == 'P') return 1;//비김
		if (fr == 'R') return 2;
	}
	if (base == 'R') {//바위
		if (fr == 'S') return 2;
		if (fr == 'P') return 0;
		if (fr == 'R') return 1;//비김
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int r,n;
	cin >> r;
	vector<char>sk(r); //라운드
	for (int i = 0; i < r; i++) cin >> sk[i];
	cin >> n;
	vector<vector<char>>friends(n,vector<char>(r)); //친구
	for (int i = 0; i < n; i++)//친구
		for (int j = 0; j < r; j++)//라운드
			cin >> friends[i][j];


	//문제 해결
	int score = 0, max_score = 0;
	for (int j = 0; j < r; j++) {
		int arr[3] = { 0,0,0 };
		for (int i = 0; i < n; i++) {
			arr[0] += check_win('S', friends[i][j]);
			arr[1] += check_win('P', friends[i][j]);
			arr[2] += check_win('R', friends[i][j]);

			score += check_win(sk[j], friends[i][j]);
		}
		max_score += max(arr[0], max(arr[1], arr[2]));
	}

	//결과 출력
	cout << score << '\n' << max_score << '\n';;
		
}