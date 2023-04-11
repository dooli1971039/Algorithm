#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char tmp;
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> tmp;
            if (tmp == 'F') {
                if ((i + j) % 2 == 0) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
}