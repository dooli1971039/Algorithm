#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c,d;
char result;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<3;i++){
        cin>>a>>b>>c>>d;
        int ssum=a+b+c+d;
        if(ssum==0) result='D';
        else if(ssum==1) result='C';
        else if(ssum==2) result='B';
        else if(ssum==3) result='A';
        else result='E';

        cout<<result<<'\n';
    }
}