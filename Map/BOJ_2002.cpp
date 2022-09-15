#include <iostream>
#include <map>
#include <vector>
using namespace std;

int countCar(int n, map<string, int> &mp, vector<string> &out) {
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (mp[out[i]] > mp[out[j]]) { //먼저 나온 차의 값이 더 크면 추월한 것
                ans += 1;
                break;
            }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<string, int> mp;

    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        mp[str] = i; //들어가는 순서
    }

    vector<string> out(n);
    for (int i = 0; i < n; i++)
        cin >> out[i];

    int ans = countCar(n, mp, out);
    cout << ans;
}