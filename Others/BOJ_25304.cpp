#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int money, num;
    cin >> money >> num;
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        money -= a * b;
    }
    if (money == 0)
        cout << "Yes";
    else
        cout << "No";
}