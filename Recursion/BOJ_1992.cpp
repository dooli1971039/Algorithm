#include <iostream>

using namespace std;

int arr[64][64];
int n;
string result = "";

bool check(int r, int c, int len) {
    int num = arr[r][c];
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            if (arr[i + r][j + c] != num)
                return false;

    return true;
}

void checkAndDivide(int r, int c, int len) {
    if (len == 1 || check(r, c, len)) {
        result += to_string(arr[r][c]);
        return;
    }

    // 4분면으로 분할
    result += "(";
    len /= 2;
    checkAndDivide(r, c, len);             // 왼쪽 위
    checkAndDivide(r, c + len, len);       // 오른쪽 위
    checkAndDivide(r + len, c, len);       // 왼쪽 아래
    checkAndDivide(r + len, c + len, len); // 오른쪽 아래
    result += ")";
}

int main() {
    cin >> n;

    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            arr[i][j] = (tmp[j] - '0');
        }
    }

    checkAndDivide(0, 0, n);
    cout << result;
}