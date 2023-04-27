#include <iostream>

using namespace std;

int main()
{
    string str; int n;
    cin>>str>>n;
    
    int result=0,tmp;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]>='A' && str[i]<='Z'){
            tmp=(str[i]-'A')+10;
        }else{
            tmp=(str[i]-'0');
        }
        
        int ppow=1;
        for(int j=i;j<str.size()-1;j++){
            ppow*=n;
        }
        result+=ppow*tmp;
    }
    cout<<result;
    return 0;
}