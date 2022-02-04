#include <iostream>
#include <algorithm>
#include <numeric> //accumulate() 들어있다.

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) cin >> arr[i];


	//문제 해결

	// 첫번째 인자는 시작지점 = 배열의 포인터
	// 두번째 인자는 끝나는지점 + 1 = a(배열의 포인터) + 배열의 크기
	sort(arr, arr + 9);
	
	//배열 시작 주소, 배열 끝 주소, 초기값
	sum = accumulate(arr, arr + 9, sum); 

	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 9; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				
				//결과 출력
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					else cout << arr[k] << '\n';
				}
				return 0;
			}
		}
	}

}