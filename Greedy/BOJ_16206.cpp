#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a,b, num, tmp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m; //������ũ ����, �ڸ� �� �ִ� Ƚ��
	vector<int>v1; //������ũ ���� == 10�� ���
	vector<int>v2; //������ũ ���� ==10�� ����� �ƴ� ��

	num = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 10) continue;
		else if (a == 10) num++;
		else if (a % 10 == 0) v1.push_back(a);
		else v2.push_back(a);
	}
	sort(v1.begin(), v1.end()); //����
	sort(v2.begin(), v2.end()); //����

	v1.insert(v1.end(), v2.begin(), v2.end()); //�� ���͸� ��ġ��

	while (m>0 && !v1.empty()) {
		tmp = v1[0];
		b = tmp / 10; 
		if (tmp % 10 == 0) { //10�� ����� ��
			if (b - 1 <= m) { //Į�� Ƚ�� �Ǵ�
				num += b;
				m -= (b - 1);
			}
			else {
				num += m;
				break;
			}
		}
		else { //10�� ����� �ƴ� ��
			if (b <= m) {//Į�� Ƚ�� �Ǵ�
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