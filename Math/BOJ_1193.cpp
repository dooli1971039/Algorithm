#include <iostream>

using namespace std;

string calc_num(int n) {
    int cnt = 0, i;
    bool dir = true;
    for (i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cnt++;
            if (cnt == n) {
                if (dir) {
                    return to_string(i - j) + "/" + to_string(j + 1);
                } else {
                    return to_string(j + 1) + "/" + to_string(i - j);
                }
            }
        }
        dir = !dir;
    }
    return "";
}

int main() {
    int n;
    cin >> n;
    cout << calc_num(n);
}