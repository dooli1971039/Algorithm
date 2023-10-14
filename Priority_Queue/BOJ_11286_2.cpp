#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

struct cmp{
    bool operator()(const ll &a, const ll &b){
        if(abs(a)!= abs(b)) return abs(a) > abs(b);
        return a>b;
    }
};

int main(){
    int n;
    cin>>n;

    priority_queue<ll, vector<ll>, cmp> pq;
    
    ll tmp;
    while(n--){
        cin>>tmp;
        if(tmp==0){
            if(pq.empty()) cout<<"0\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }else{
            pq.push(tmp);
        }
    }

}