#include <iostream>

using namespace std;

int arr[20];
int n, s;
int cnt = 0;

void back(int current, int ssum) {
    if (current == n) {
        if (ssum == s) {
            cnt++;
        }
        return;
    }

    back(current + 1, ssum);                // arr[current]를 더하지 않는 경우
    back(current + 1, ssum + arr[current]); // arr[current]를 더하는 경우
}

int main() {
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    back(0, 0);

    // 크기가 양수인 부분수열만 카운트 해야 하는데, s==0인 경우는 공집합도 포함될 수 있어 -1 필요
    if (s == 0)
        cout << cnt - 1;
    else
        cout << cnt;
}