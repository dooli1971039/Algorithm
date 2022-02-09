#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main() {
	//기타 => 줄 6개, 각 줄마다 프렛 P개

	//입력
	int n,p;
	cin >> n >> p;
	vector<stack<int>>v(7); //줄:1~6번
	
	//문제 해결
	int count = 0;
	for (int i = 0; i < n; i++) { //입력받는 음의 개수
		int line, pp;
		cin >> line >> pp;
		
		//비어있지 않고, 손을 떼야 할때
		if (!v[line].empty() && v[line].top() > pp) { //비어있는데 top()하면 에러
			while (!v[line].empty() && v[line].top() > pp) {
				v[line].pop();
				count++;
			}
		}

		//추가하기
		if (v[line].empty() || v[line].top() < pp) { 
			count++;
			v[line].push(pp);	
		}
	}
	
	//결과 출력
	cout << count << '\n';
}