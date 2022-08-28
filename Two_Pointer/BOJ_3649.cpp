#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    
    while(true){
    string a; getline(cin,a);
    if(a=="") return 0;
    
    int width, n, tmp; //width는 센티
    if(a.size()==2) width=(a[0]-'0')*10 +a[1]-'0';
    else width=a[0]-'0';

    cin>>n;

    vector<int>arr(n); //블록: 나노미터
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin.ignore();
    sort(arr.begin(),arr.end());
    
    int f=0,b=n-1;
    bool check=false;
    while(f<b){
        if(arr[f]+arr[b]==width*10000000){
            cout<<"yes "<<arr[f]<<" "<<arr[b]<<"\n";
            check=true;
            break;
        }else if(arr[f]+arr[b]<width*10000000) f++;
        else b--;
    }
    if(!check) cout<<"danger\n";
    }

}
