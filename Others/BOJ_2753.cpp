#include <iostream>

using namespace std;
int a;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a;
    if((a%4==0 && a%100!=0) || a%400==0) cout<<1;
    else cout<<0;
}