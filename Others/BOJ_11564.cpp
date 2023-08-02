#include <iostream>
using namespace std;

int main() {
    long long k, start, end;
    cin >> k >> start >> end;

    long long result;
    if (start == 0 || end == 0 || (start < 0 && end > 0)) { // 0을 포함하는 경우
        result = 1 + abs(start) / k + end / k;
    } else { // 한쪽에 치우친 경우
        start = abs(start);
        end = abs(end);

        if (start > end)
            swap(start, end); // 무조건 end가 더 크게 만들기

        result = end / k - start / k;
        if (start % k == 0) {
            result += 1;
        }
    }

    cout << result;
}