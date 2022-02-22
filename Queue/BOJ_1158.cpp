#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n,k;
	cin >> n>>k;
	
	queue<int>q;
	for (int i = 1; i <= n; i++)q.push(i);

	cout << "<";

	//���� �ذ�
	while (q.size() > 1) {
		for (int i = 1; i < k; i++) {
			int tmp = q.front();
			q.pop(); //�տ��� ����
			q.push(tmp); //�ڿ� �ٽ� �ִ´�
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">\n";
}