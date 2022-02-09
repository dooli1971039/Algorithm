#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main() {
	//��Ÿ => �� 6��, �� �ٸ��� ���� P��

	//�Է�
	int n,p;
	cin >> n >> p;
	vector<stack<int>>v(7); //��:1~6��
	
	//���� �ذ�
	int count = 0;
	for (int i = 0; i < n; i++) { //�Է¹޴� ���� ����
		int line, pp;
		cin >> line >> pp;
		
		//������� �ʰ�, ���� ���� �Ҷ�
		if (!v[line].empty() && v[line].top() > pp) { //����ִµ� top()�ϸ� ����
			while (!v[line].empty() && v[line].top() > pp) {
				v[line].pop();
				count++;
			}
		}

		//�߰��ϱ�
		if (v[line].empty() || v[line].top() < pp) { 
			count++;
			v[line].push(pp);	
		}
	}
	
	//��� ���
	cout << count << '\n';
}