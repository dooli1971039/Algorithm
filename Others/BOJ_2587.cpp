#include <iostream>
#include <algorithm>
using namespace std;

int ssum;
int a[5];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<5;i++){
        cin>>a[i];
        ssum+=a[i];
    }
    sort(a,a+5);
    cout<<ssum/5<<'\n';
    cout<<a[2];
}