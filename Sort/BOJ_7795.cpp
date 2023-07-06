#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solution() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    vector<int> b(m, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnt = 0;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (b[i] >= a[j]) { // a가 더 크지 않으면 넘어가기
                continue;
            }
            cnt += (a.size() - j);
            break;
        }
    }
    cout << cnt << '\n';
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        solution();
    }
}