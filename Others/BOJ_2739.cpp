#include <iostream>
#include <vector>
using namespace std;

int arr[100][100];
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            cout << tmp + arr[i][j] << ' ';
        }
        cout << '\n';
    }
}