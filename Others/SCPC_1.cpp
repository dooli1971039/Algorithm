#include <iostream>

using namespace std;

int solution() {
    int n, a, b;
    cin >> n >> a >> b;

    // 무조건 a가 더 작게
    if (a > b)
        swap(a, b);

    int aNum = n / a;
    int leftApple;
    while (true) {
        leftApple = n - a * aNum;
        if (leftApple % b == 0) {
            return aNum + leftApple / b;
        }
        aNum--;
    }
}

int main(int argc, char **argv) {
    int T;

    cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        cout << "Case #" << test_case + 1 << '\n';
        cout << solution() << '\n';
    }

    return 0;
}