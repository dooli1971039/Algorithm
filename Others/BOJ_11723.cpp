#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int SIZE=21;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;
    vector<bool> s(SIZE,false); // 0~20의 배열을 false로 초기화

    for(int i=0;i<n;i++){
        string command;
        cin>>command;

        if(command=="all") 
            s.assign(SIZE,true); //true의 값으로 SIZE개의 원소를 할당
        else if(command=="empty") 
            s.assign(SIZE,false);
        else{
            int x; cin>>x;
            if(command=="add") 
                s[x]=true;
            else if(command=="remove") 
                s[x]=false;
            else if(command=="check") 
                cout<<s[x]<<'\n'; // true이면 1을, false이면 0을 출력
            else if(command=="toggle")
                s[x]=!s[x]; // true이면 false를, false면 true를 대입
        }
    }
}