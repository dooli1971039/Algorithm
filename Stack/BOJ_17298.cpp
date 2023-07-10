#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 백준 17298 오큰등수
 * 주의사항1: 입력이 10^6개가 들어올 수 있기 때문에, 이중 for문으로 돌면 시간초과가 나는 문제이다.
 * 주의사항2: 수열의 원소가 전부 다르다는 조건이 없기 때문에, pop하는 조건을 체크할 때 주의해야 한다.
 *           (오큰등수는 자신보다 반드시 커야 한다.)
 */

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> st;
    vector<int> result(n, 0);

    // 역순으로 체크
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.empty())
            result[i] = -1;
        else {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }

    for (auto num : result)
        cout << num << ' ';
}
