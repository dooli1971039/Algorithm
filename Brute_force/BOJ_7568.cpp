#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//�Է�
	int n;
	cin >> n;
	vector<pair<int,int>>arr;

	int w, h;
	for (int i = 0; i < n; i++) {
		cin >> w >> h;
		arr.push_back(make_pair(w, h));
	}
	
	//���� �ذ�
	for (int i = 0; i < n; i++) {
		int count = 1;
		for (int j = 0; j < n; j++) {
			//�ڽź��� ��ġ�� ū ����� ī��Ʈ
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
				count++;
		}
		cout << count << ' ';
	}

	cout << '\n';
}