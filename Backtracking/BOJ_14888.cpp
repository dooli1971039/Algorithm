#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int operators[10]; // 0은 +, 1은 -, 3은 x, 4는 /
bool used[10];

int n;
int arr[11];
int operOrder[10];
vector<long long> results;

long long calcNum() {
    long long result = arr[0];
    for (int i = 0; i < n - 1; i++) {
        if (operOrder[i] == 0) {
            result += arr[i + 1];
        } else if (operOrder[i] == 1) {
            result -= arr[i + 1];
        } else if (operOrder[i] == 2) {
            result *= arr[i + 1];
        } else {
            result /= arr[i + 1];
        }
    }
    return result;
}

void back(int cnt) {
    if (cnt == n - 1) { // 연산자를 다 사용했을 때
        long long num = calcNum();
        results.push_back(num);
        return;
    }

    int dup = -1;
    for (int i = 0; i < n - 1; i++) {
        if (dup != operators[i] && !used[i]) {
            dup = operators[i];
            used[i] = true;
            operOrder[cnt] = operators[i];
            back(cnt + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int tmp = 0, cur = 0;
    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            operators[cur] = i;
            cur++;
        }
    }

    back(0);

    sort(results.begin(), results.end());
    cout << results[results.size() - 1] << '\n' << results[0];
}