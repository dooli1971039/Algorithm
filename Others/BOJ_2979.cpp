#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> arr(101, 0);

    for (int i = 0; i < 3; i++) {
        int s, e;
        cin >> s >> e;

        for (int j = s; j < e; j++) {
            arr[j]++;
        }
    }

    int fair = 0;
    for (int i = 1; i < 101; i++) {
        if (arr[i] == 0)
            continue;
        else if (arr[i] == 1)
            fair += a;
        else if (arr[i] == 2)
            fair += 2 * b;
        else if (arr[i] == 3)
            fair += 3 * c;
    }

    cout << fair;
}