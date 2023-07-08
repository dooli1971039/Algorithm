#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long reverseNum(string str) {
    reverse(str.begin(), str.end());
    return stoll(str);
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr;

    string num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(reverseNum(num));
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}