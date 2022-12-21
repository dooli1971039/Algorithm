#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k,q,l,b,n,p;
    cin>>k>>q>>l>>b>>n>>p;

    cout<<1-k<<' '<<1-q<<' '<<2-l<<' '<<2-b<<' '<<2-n<<8-p<<'\n';
}