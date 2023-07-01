#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int cnt = 0; // 0 -> 1 또는 1 -> 0 으로 바뀌는 횟수
    for (int i = 1; i < str.size(); i++) {
        if (str[i] != str[i - 1]) {
            cnt++;
        }
    }
    cout << (cnt + 1) / 2;
}