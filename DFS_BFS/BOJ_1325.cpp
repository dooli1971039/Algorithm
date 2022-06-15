#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//다시

vector<int> graph[10001];
vector<int> hacking;//각 컴퓨터마다 해킹할 수 있는 컴퓨터 개수
//해킹은 신뢰방향의 반대 방향으로 이루어짐
//c -> b -> a로 노드가 주어지면
//a를 해킹했을 때,b,c도 해킹 가능하다.

vector<int> visited;

int mmax = 0; //가장 많이 해킹할 수 있는 컴퓨터 개수

void dfs(int node) {
	hacking[node]++; //해당 노드를 통해 해킹 가능한 컴퓨터 개수
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
	//입력
	int n, m; //컴퓨터 개수, 신뢰하는 관계 개수
	cin >> n >> m; //n<=10000, m<=100000

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); //a가 b를 신뢰한다.
							   //b를 통해 a를 해킹할 수 있다.
	}

	//문제 해결
	hacking = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++) {//컴퓨터 번호는 1부터 시작
		visited = vector<int>(n + 1, 0);

		visited[i] = 1;
		dfs(i);
	}

	//결과 출력
	for (int i = 1; i <= n; i++) {
		if (hacking[i] == mmax) {
			cout << i << " ";
		}
	}cout << '\n';
}
