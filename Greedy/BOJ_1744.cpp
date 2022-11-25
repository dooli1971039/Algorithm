#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * <1774번 수 묶기>
 *
 * 1) 벡터로 입력받아 정렬하기
 * 2) 계산 시 주의사항
 *   i) 곱하기는 음수는 음수끼리, 양수는 양수끼리
 *   ii) 곱할 때는 절댓값이 큰 것끼리 (ex. 2,3,4,5 => 5*4+3*2 > 5*3+4*2)
 *   iii) 0이 존재하고, 전부 곱하고 나서 음수가 남아있으면 0과 음수를 곱함
 *   iv) 0이 존재하나, 전부 곱하고 나서 음수가 없으면, 0은 그냥 더함 (다른 수와 곱하지 않을 것)
 *   v) 1은 다른 수와 곱하지 않고 그냥 더할 것
 *   vi) 입력받은 벡터의 크기가 1일 경우, 그냥 그 수 그대로 출력할 것
 */

int solution(vector<int> &num) {
    sort(num.begin(), num.end());

    if (num.size() == 1) {
        return num[0];
    }

    int i = 0, sum = 0;
    while (num[i] < 0) {      //음수 부분 계산
        if (num[i + 1] < 0) { // 둘 다 음수
            sum += num[i] * num[i + 1];
        } else if (num[i + 1] > 0) { // 0 이 없는 채로 음수가 남았으니, 음수를 그대로 더한다.
            sum += num[i];
        }
        // num[i+1]==0 일 때는 num[i]와 0을 곱하여 더하기 때문에 계산 X
        i += 2;
    }

    int j = num.size() - 1;
    while (j >= 0 && num[j] > 0) { //양수 부분 계산
        if (j - 1 < 0) {
            sum += num[j];
            break;
        }
        if (num[j - 1] > 0) {
            if (num[j] == 1 || num[j - 1] == 1) { // 1은 곱하지 않고 더하기
                sum += num[j] + num[j - 1];
            } else {
                sum += num[j] * num[j - 1];
            }
        } else if (num[j - 1] <= 0) {
            sum += num[j];
            break;
        }
        j -= 2;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int result = solution(num);

    cout << result;
}