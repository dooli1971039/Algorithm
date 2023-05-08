#include <iostream>

using namespace std;

void solution(){
    int n;
    cin>>n;  
    cout<<n/25<<' ';
    n%=25;
    cout<<n/10<<' ';
    n%=10;
    cout<<n/5<<' ';
    n%=5;
    cout<<n<<'\n';
}

int main()
{
    int t; cin>>t;
    for(int i=0;i<t;i++){
        solution();
    }    
}