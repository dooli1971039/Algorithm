#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n,m; cin>>n>>m;
    deque<int> dq;

    for(int i=1;i<=n;i++) dq.push_back(i); //1~n 까지의 dq 만들기

    int count=0, index, tmp;
    for(int i=0;i<m;i++){
        cin>>tmp;

        for(int j=0;j<dq.size();j++)
            if(dq[j]==tmp){
                index=j;
                break;
            }
        
        if(index < dq.size() - index ){ //앞에서 빼서 뒤에 넣는다
            while(dq.front()!=tmp){
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
            dq.pop_front();

        }else{ //뒤에서 빼서 앞에 넣기
            while(dq.front()!=tmp){ //뽑기만 하는 것은 front에서만 가능하다
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
            dq.pop_front();
        }
    }

    cout<<count;
}