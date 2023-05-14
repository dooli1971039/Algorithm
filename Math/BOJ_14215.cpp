#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 막대는 줄이는 것만 가능함
 * c > a + b 인 경우에는 그냥 출력
 * c <= a + b 인 경우에는 c = a + b -1이어야 함
*/

int main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if(a[0] + a[1] > a[2]) cout << a[0] + a[1] + a[2];
    else cout << (a[0] + a[1]) * 2 - 1;
}