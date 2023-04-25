#include <iostream>
using namespace std;
int main()
{
    string n;
    cin>>n;
    
    int result=0;
    for(int i=n.size()-1;i>=0;i--){
        int tmp=0;
        if(n[i]>='A' && n[i]<='F'){
            tmp=n[i]-'A'+10;
        }else{
            tmp=n[i]-'0';
        }
        
        int temp=1;
        for(int j=0;j<(n.size()-i-1);j++){
            temp*=16;
        }
        
        result+= tmp*temp;
    }
    
    cout<<result;
    return 0;
}
