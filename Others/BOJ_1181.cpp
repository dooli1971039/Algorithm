#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

//set의 정렬 기준을 바꾸기 위해 구조체 선언 및 operator() 오버로딩
struct sorting {
	bool operator() (const string& a, const string& b) const {
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	}
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n; string tmp;
	cin >> n;
	set<string, sorting>ss; //두번째 인자에 정렬기준

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		ss.insert(tmp);
	}

	for (auto str : ss) cout << str << '\n';
	
}