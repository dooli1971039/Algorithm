#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

//set�� ���� ������ �ٲٱ� ���� ����ü ���� �� operator() �����ε�
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

	//�Է�
	int n; string tmp;
	cin >> n;
	set<string, sorting>ss; //�ι�° ���ڿ� ���ı���

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		ss.insert(tmp);
	}

	for (auto str : ss) cout << str << '\n';
	
}