#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;	cin >> n;
	vector<int> money(n);
    for(int i=0;i<n;i++) cin>>money[i];

    // 원래 내려했던 돈이 많은 사람이 앞쪽에 있어야 한다
    sort(money.begin(),money.end()); 
    reverse(money.begin(),money.end());

    //sort(money.begin(),money.end(),greater<>()); 

    long long ans=0; // 주의하기!!
    for(int i=0;i<n;i++)
        ans+=((money[i]-i)>0)?(money[i]-i):0;
    
    cout<<ans;
    
}