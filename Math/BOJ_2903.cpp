#include <iostream>
using namespace std;

int calc(int a,int b){
    int result=1;
    for(int i=0;i<b;i++){
        result*=a;
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    
    cout<<(calc(2,n)+1)*(calc(2,n)+1);
}