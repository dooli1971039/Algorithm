#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n; cin >> n;
	vector<queue<string>>q(n+1); //�������� ���� ���ڿ�
	string tmp;
	getline(cin, tmp); //������ cin���� ���� �Է¹ް� ���� ���๮�� ó��
	for (int i = 0; i < n+1; i++) {
		getline(cin, tmp);
		istringstream ss(tmp);
		string stringBuffer;
		while (getline(ss, stringBuffer, ' ')) { //�������� �����Ͽ� ����
			q[i].push(stringBuffer);
		}
	}

	bool check = false;
	//���� �ذ�
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

	//��� ���
	//�������� �ܾ ���� ���� �ִ�.
	//�̰� üũ ���ϸ� Ʋ��
	for (int i = 0; i < n; i++) {
		if (!q[i].empty()) {
			cout << "Impossible\n";
			return 0;
		}
	}
	
	cout << "Possible\n";
}