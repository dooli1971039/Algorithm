#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

    string str;
    cin >> str;
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += arr[str[i] - 'A'];
    }
    cout << sum;
}