#include <iostream>
#include <algorithm>
#include <numeric> //accumulate() ����ִ�.

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) cin >> arr[i];


	//���� �ذ�

	// ù��° ���ڴ� �������� = �迭�� ������
	// �ι�° ���ڴ� ���������� + 1 = a(�迭�� ������) + �迭�� ũ��
	sort(arr, arr + 9);
	
	//�迭 ���� �ּ�, �迭 �� �ּ�, �ʱⰪ
	sum = accumulate(arr, arr + 9, sum); 

	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 9; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				
				//��� ���
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					else cout << arr[k] << '\n';
				}
				return 0;
			}
		}
	}

}