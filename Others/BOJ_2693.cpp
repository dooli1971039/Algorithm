#include <iostream>

using namespace std;

int arr[10] = {0};

void bubble_rev() {
    int tmp = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void solution() {
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    bubble_rev();
    cout << arr[2] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}