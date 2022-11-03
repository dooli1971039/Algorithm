// 다른 사람 풀이보고 겨우 이해함.
// 나중에 다시 풀어볼 것
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int SIZE = 1e6;
/*
    오등큰수: 자신보다 오른쪽에 있는 수 중, 빈도수가 더 큰 수인데 가장 왼쪽
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> f(SIZE + 1, 0); // 모두 0으로 초기화 해둠
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        f[arr[i]]++;
    }

    stack<int> st;
    vector<int> result(n, -1); //오등큰수가 없을 경우 -1이라서
    for (int i = 0; i < n; i++) {
        int num = arr[i];  // 수열의 원소
        int freq = f[num]; // num이 등장한 횟수

        while (!st.empty() && f[arr[st.top()]] < freq) {
            result[st.top()] = num;
            st.pop();
        }
        st.push(i); //위치 (왼쪽부터 들어가게 된다.)
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
}