#include <iostream>

using namespace std;

void solution() {
    string str;
    cin >> str;

    int front = 26 * 26 * (str[0] - 'A') + 26 * (str[1] - 'A') + (str[2] - 'A');
    int back = (str[4] - '0') * 1000 + (str[5] - '0') * 100 + (str[6] - '0') * 10 + (str[7] - '0');

    int diff = front - back;
    if (diff >= -100 && diff <= 100)
        cout << "nice\n";
    else
        cout << "not nice\n";
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solution();

    return 0;
}