#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;
    deque<int> dq;

    for(int i=0;i<n;i++){
        string str;
        cin>>str;

        if(str=="pop_front"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                cout<<dq.front()<<'\n';
                dq.pop_front();
            }
        }else if(str=="pop_back"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                cout<<dq.back()<<'\n';
                dq.pop_back();
            }
        }else if(str=="front"){
            if(dq.empty()) cout<<-1<<'\n';
            else cout<<dq.front()<<'\n';
        }else if(str=="back"){
            if(dq.empty()) cout<<-1<<'\n';
            else cout<<dq.back()<<'\n';
        }else if(str=="size") cout<< dq.size()<<'\n';
        else if(str=="empty") cout<< dq.empty()<<'\n';
        else{
            int tmp; cin>>tmp;
            if(str=="push_front") dq.push_front(tmp);
            else dq.push_back(tmp);
        }
    }
}