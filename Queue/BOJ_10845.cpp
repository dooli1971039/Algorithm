#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n,tmp; cin>>n;
    queue<int> q;

    for(int i=0;i<n;i++){
        string str;
        cin>>str;

        if(str=="push"){
            cin>>tmp;
            q.push(tmp);
        }else if(str=="pop"){
            if(q.empty()) cout<<-1<<'\n';
            else {
                cout<<q.front()<<'\n';
                q.pop();
            }
        }else if(str=="size") cout<<q.size()<<'\n';
        else if(str=="empty"){
            if(q.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }else if(str=="front"){
            if(q.empty()) cout<<-1<<'\n';
            else cout<<q.front()<<'\n';
        }else if(str=="back"){
            if(q.empty()) cout<<-1<<'\n';
            else cout<<q.back()<<'\n';
        }
    }
}