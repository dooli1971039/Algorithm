#include <iostream>
#include <vector>
using namespace std;

int arr[128][128];
int n, white, blue;

bool checkBox(int num, int sr, int sc, int er, int ec) {
    for (int i = sr; i < er; i++) {
        for (int j = sc; j < ec; j++) {
            if (num != arr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solution(int sr, int sc, int len) {
    if (len == 0)
        return;

    if (!(sr >= 0 && sc >= 0 && sr + len <= n && sc + len <= n))
        return;

    if (checkBox(arr[sr][sc], sr, sc, sr + len, sc + len)) {
        // true이면 white,blue 개수 바꾸기
        arr[sr][sc] ? blue++ : white++;

    } else {
        len /= 2;
        solution(sr, sc, len);             // 좌측 위
        solution(sr + len, sc, len);       // 좌측 아래
        solution(sr, sc + len, len);       // 우측 위
        solution(sr + len, sc + len, len); // 우측 아래
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    solution(0, 0, n);
    cout << white << '\n' << blue;
}