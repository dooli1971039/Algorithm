//답보고 이해함
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n; cin>>n;
    stack<int>ss;

    int cnt=1;
    string ans;

    while(n--){
        int tmp;
        cin>>tmp;

        while(cnt <= tmp){ // 이 경우엔 값을 계속 추가해야함
            ss.push(cnt++);
            ans+="+\n";
        }

        if(ss.top()!=tmp){
            ans="NO\n";
            break;
        }
        ss.pop();
        ans+="-\n";
    }

    cout<<ans;
}
//////////////////////////////////////////////////////
/*
현재 처리를 필요로 하는 수는 cnt이다. (cnt의 값은 계속 증가해야 한다)
cnt 이상인 값 tmp가 주어지면 "그 값을 pop할 수 있게" cnt가 tmp가 될 때 까지 push를 해야 한다.
만약 S.top()과 tmp가 일치하지 않는다면 올바르지 않은 수열이다.
*/