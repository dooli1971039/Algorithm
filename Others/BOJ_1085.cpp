#include <iostream>
using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int num = min(x, y);
    num = min(abs(w - x), num);
    num = min(abs(y - h), num);
    cout << num;
}