//답보고 이해
#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n; cin>>n;
    stack<int>ss;

    long long count=0;
    long long h;

    while(n--){
        cin>>h;

        //스택의 top이 새로운 빌딩보다 작거나 같으면, 새로운 빌딩을 볼 수 없다.
        //높을 때까지 pop한다.
        while(!ss.empty() && ss.top()<=h) ss.pop();

        //남아있는 빌딩의 개수를 추가하고
        //새로운 빌딩을 넣어준다
        count += ss.size();
        ss.push(h);

    }
    cout<<count;

}