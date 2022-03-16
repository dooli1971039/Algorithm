#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n; cin >> n;
	vector<queue<string>>q(n+1); //마지막은 기준 문자열
	string tmp;
	getline(cin, tmp); //위에서 cin으로 정수 입력받고 남은 개행문자 처리
	for (int i = 0; i < n+1; i++) {
		getline(cin, tmp);
		istringstream ss(tmp);
		string stringBuffer;
		while (getline(ss, stringBuffer, ' ')) { //공백으로 구분하여 넣음
			q[i].push(stringBuffer);
		}
	}

	bool check = false;
	//문제 해결
	int queue_size = q[n].size();
	for (int i = 0; i < queue_size; i++) {
		string base_word = q[n].front();
		for (int j = 0; j < n; j++) {
			if (!q[j].empty() && q[j].front() == base_word) {
				q[j].pop();
				q[n].pop();
				check = true;
				break;
			}
		}
		if (check == false) {
			cout << "Impossible\n";
			return 0;
		}
		else {
			check = false;
		}
	}

	//결과 출력
	//마지막에 단어가 남을 수도 있다.
	//이거 체크 안하면 틀림
	for (int i = 0; i < n; i++) {
		if (!q[i].empty()) {
			cout << "Impossible\n";
			return 0;
		}
	}
	
	cout << "Possible\n";
}