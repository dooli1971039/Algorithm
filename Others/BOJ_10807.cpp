#include <iostream>
#include <algorithm>

using namespace std;

int n,v,tmp;
int arr[205];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>tmp;
        arr[tmp+100]++;
    }
    cin>>v;
    cout<<arr[v+100];

}