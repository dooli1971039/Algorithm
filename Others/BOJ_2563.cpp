#include <iostream>

using namespace std;

int arr[101][101];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (x + j > 100 || y + k > 100)
                    continue;
                arr[x + j][y + k] = 1;
            }
        }
    }

    int result = 0;
    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            result += arr[i][j];
        }
    }
    cout << result;
}