#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[10];
long long a,b,c,result;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>a>>b>>c;
    result=a*b*c;
    string str=to_string(result);

    for(int i=0;i<str.size();i++){
        arr[str[i]-'0']++;
    }
    for(int i=0;i<10;i++) cout<<arr[i]<<'\n';
}

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int A, B, C;
//   cin >> A >> B >> C;
//   int t=A*B*C;
//   int d[10] = {};
//   // 계산 결과를 자릿수별로 확인하여 저장
//   while (t>0) {
//     d[t%10]++;
//     t/=10;
//   }
//   for (int i=0; i<10; ++i) cout << d[i] << '\n';
// }