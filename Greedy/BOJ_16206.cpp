#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a,b, num, tmp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m; //롤케이크 개수, 자를 수 있는 횟수
	vector<int>v1; //롤케이크 길이 == 10의 배수
	vector<int>v2; //롤케이크 길이 ==10의 배수가 아닌 것

	num = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 10) continue;
		else if (a == 10) num++;
		else if (a % 10 == 0) v1.push_back(a);
		else v2.push_back(a);
	}
	sort(v1.begin(), v1.end()); //정렬
	sort(v2.begin(), v2.end()); //정렬

	v1.insert(v1.end(), v2.begin(), v2.end()); //두 벡터를 합치기

	while (m>0 && !v1.empty()) {
		tmp = v1[0];
		b = tmp / 10; 
		if (tmp % 10 == 0) { //10의 배수일 때
			if (b - 1 <= m) { //칼질 횟수 판단
				num += b;
				m -= (b - 1);
			}
			else {
				num += m;
				break;
			}
		}
		else { //10의 배수가 아닐 때
			if (b <= m) {//칼질 횟수 판단
				num += b;
				m -= b;
			}
			else {
				num += m;
				break;
			}
		}
		v1.erase(v1.begin());
	}

	cout << num << '\n';	
}