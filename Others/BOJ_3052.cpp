#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> ss;
    int n;
    for(int i=0;i<10;i++){
        cin>>n;
        ss.insert(n%42);
    }
    
    int num=0;
    for(auto i:ss){
        num++;
    }
    
    cout<<num;
    return 0;
}