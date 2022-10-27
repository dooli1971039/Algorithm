///풀긴 했지만 다시 해보자
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n,tmp; cin>>n;
    stack<pair<int,int>>ss;

    for(int i=1;i<=n;i++){
        cin>>tmp;

        if(ss.empty()){
            cout<<0<<' ';
        }else if(ss.top().first < tmp){
            while(!ss.empty() && ss.top().first<tmp){
                ss.pop();
            }
            if(ss.empty()){
                cout<<0<<' ';
            }else{
                cout<<ss.top().second<<' ';
            }
        }else{
            cout<<ss.top().second<<' ';
        }

        ss.push(make_pair(tmp,i));
    }

}


//////////////////////////////
// 이렇게도 가능하다.
/*
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
stack<pair<int,int>> tower;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;  
  tower.push({100000001, 0});
  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;
    while (tower.top().X < height)
      tower.pop();    
    cout << tower.top().Y << " ";
    tower.push({height, i});      
  }
}
*/