#include <iostream>
using namespace std;

int main(){
        ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n, num;
	int arr[10001]={0,};
	cin >> n;
	
	for(int i=0; i<n ;i++){
		cin>>num;
		arr[num] = arr[num] + 1; //숫자 카운트  
	}
	
	for(int i=1; i<10001; i++){
		for(int j=1; j<=arr[i]; j++){ //숫자만큼 반복 출력 
			cout<<i<<'\n';
		}
	}
}