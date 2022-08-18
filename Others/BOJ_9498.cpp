#include <iostream>

using namespace std;
int a;
char b;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a;
    if(a>=90) b='A';
    else if(a>=80) b='B';
    else if(a>=70) b='C';
    else if(a>=60) b='D';
    else b='F';
    cout<<b;
}