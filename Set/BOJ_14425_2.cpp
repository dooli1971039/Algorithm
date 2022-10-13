#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<string> ss;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        ss.insert(str);
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        cin >> str;
        count += ss.count(str); // ss.count(k) : 원소 k의 개수를 반환 (0,1)
    }

    //결과 출력
    cout << count << '\n';
}