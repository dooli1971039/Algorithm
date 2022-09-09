#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    
    int n; cin>>n;
    int money=0;
    
    string str;
    getline(cin,str);
    for(int i=0;i<n;i++){
        getline(cin,str);
        
        int hh=(str[0]-'0')*10 + (str[1]-'0');
        int mm=(str[3]-'0')*10 + (str[4]-'0');
        int dd=(str[6]-'0')*10 + (str[7]-'0');
        
        if(mm+dd>60){
            int out=mm+dd-60;
            
            if(hh>=7 && hh<19) money+=(60-mm)*10;
            else money+=(60-mm)*5;
            
            if(hh+1>=7 && hh+1<19) money+=out*10;
            else money+=out*5;
            
        }else{
            if(hh>=7 && hh<19) money+=dd*10;
            else money+=dd*5;
        }
        
    }
    
    cout<<money;
}
