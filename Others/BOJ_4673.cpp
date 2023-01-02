#include <iostream>
using namespace std;

int arr[10001] = {
    0,
};

void checkArr(int n) {
    int ssum = n;
    while (n) {
        ssum += n % 10;
        n /= 10;
    }
    arr[ssum] = 1;
}

int main() {
    for (int i = 1; i < 10000; i++) {
        checkArr(i);
    }
    for (int i = 1; i < 10000; i++) {
        if (arr[i] == 0)
            cout << i << '\n';
    }
}