#include <iostream>
#include <algorithm>
using namespace std;

// int a[9],b[9];

// int main() {
// 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// 	for(int i=0;i<9;i++){
//         cin>>a[i];
//         b[i]=a[i];
//     }
    
//     sort(a,a+9);

//     cout<<a[8]<<'\n';
//     for(int i=0;i<9;i++){
//         if(b[i]==a[8]){
//             cout<<i+1;
//             return 0;
//         }
//     }
// }

int n, maxvalue, maxindex;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int i = 1; i < 10; i++){
    cin >> n;
    // 전역변수의 초기값은 0이므로 바로 비교 가능합니다.
    if(maxvalue < n){
      maxvalue = n;
      maxindex = i;
    }
  }
  cout << maxvalue << "\n" << maxindex;
}

// int a[9];
// int main(void){
//   ios::sync_with_stdio(0); cin.tie(0);
//   for(int i = 0; i < 9; i++) cin >> a[i];
//   cout << *max_element(a, a+9) << '\n'; //범위내의 max값 반환
//   cout << max_element(a, a+9) - a + 1; 
// }