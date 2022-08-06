#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>c;

    if(a==b && b==c){ //다 같을 때
        cout<<10000+a*1000;
    }else if(a==b){ //2개만 같을 때
        cout<<1000+a*100;
    }else if(b==c){
        cout<<1000+b*100;
    }else if(c==a){
        cout<<1000+c*100;
    }else{
        cout<<max({a,b,c})*100;
    }
}