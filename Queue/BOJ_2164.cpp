#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n;
	cin >> n;
	queue<int> qq;

	//���� �ذ�
	for (int i = 1; i <= n; i++) qq.push(i);

	int type = 0;
	while (qq.size()!=1) { //1�� ������ Ż��
		if (type%2==0) { //�� ���� ī�� ����
			qq.pop();
		}
		else { //�� ���� ī�带 ���� �Ʒ��� �ű�
			qq.push(qq.front());
			qq.pop();
		}
		type++;
	}
	
	//��� ���
	cout << qq.front() << '\n';
}