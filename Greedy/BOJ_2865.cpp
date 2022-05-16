#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//�Է�
	int n,m,k;
	cin >> n >> m >> k; //n��, m�� �帣, ���������ο� k
	vector<float>arr(n, 0.0);
	
	int person; float ability;
	for (int i = 0; i < m; i++) { //�帣
		for (int j = 0; j < n; j++) { //�����ں� �ɷ�
			cin >> person >> ability;

			//��ü �帣�� ��Ʋ��, �������� ���� ���� �ɷ��� ����
			//��� ��ȣ�� 1������ �����ϱ� ������ person-1
			arr[person - 1] = max(ability, arr[person - 1]);
		}
	}

	//���� �ذ�
	sort(arr.begin(), arr.end(),greater<float>()); //�������� ����

	float ans = 0.0;
	for (int i = 0; i < k; i++) { 
		ans += arr[i]; //�տ������� k�� ���ϱ�
	}

	//��� ���
	cout << fixed;
	cout.precision(1); //�Ҽ��� ù°¥������ ���
	cout << ans << '\n';
}