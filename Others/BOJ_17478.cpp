#include <iostream>
using namespace std;

string str="";

void recur(int n) {
	
	string line = str;

	if (n==0) {
		cout << line << "\"����Լ��� ������?\"\n";
		cout << line << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		cout << line << "��� �亯�Ͽ���.\n";
		return ;
	}

	cout << line << "\"����Լ��� ������?\"\n";
	cout << line << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	cout << line << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	cout << line << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

	str += "____";
	recur(n - 1);

	cout << line << "��� �亯�Ͽ���.\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int n;
	cin >> n;

	//��� ���
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recur(n);
}