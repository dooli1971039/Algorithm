#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//�ٽ�

vector<int> graph[10001];
vector<int> hacking;//�� ��ǻ�͸��� ��ŷ�� �� �ִ� ��ǻ�� ����
//��ŷ�� �ŷڹ����� �ݴ� �������� �̷����
//c -> b -> a�� ��尡 �־�����
//a�� ��ŷ���� ��,b,c�� ��ŷ �����ϴ�.

vector<int> visited;

int mmax = 0; //���� ���� ��ŷ�� �� �ִ� ��ǻ�� ����

void dfs(int node) {
	hacking[node]++; //�ش� ��带 ���� ��ŷ ������ ��ǻ�� ����
	mmax = max(hacking[node], mmax);

	//cout << "node: " << node << " ,hacking: " << hacking[node]<<'\n';

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next]) {
			visited[next] = 1;
			dfs(next);
		}
	}
}

int main() {
	//�Է�
	int n, m; //��ǻ�� ����, �ŷ��ϴ� ���� ����
	cin >> n >> m; //n<=10000, m<=100000

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); //a�� b�� �ŷ��Ѵ�.
							   //b�� ���� a�� ��ŷ�� �� �ִ�.
	}

	//���� �ذ�
	hacking = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++) {//��ǻ�� ��ȣ�� 1���� ����
		visited = vector<int>(n + 1, 0);

		visited[i] = 1;
		dfs(i);
	}

	//��� ���
	for (int i = 1; i <= n; i++) {
		if (hacking[i] == mmax) {
			cout << i << " ";
		}
	}cout << '\n';
}
