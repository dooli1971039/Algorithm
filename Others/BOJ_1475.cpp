#include <iostream>
#include <algorithm>

using namespace std;

int a;
int arr[10];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>a;
    while(a>0){
        arr[a%10]++;
        a/=10;
    }
    if((arr[6]+arr[9])%2==0) arr[6]=arr[9]=(arr[6]+arr[9])/2;
    else arr[6]=arr[9]=(arr[6]+arr[9])/2+1;

    cout<<*max_element(arr,arr+10);
}