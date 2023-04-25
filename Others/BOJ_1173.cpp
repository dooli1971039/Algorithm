#include <iostream>

using namespace std;

int main()
{
    int N,m,M,T,R,t,mb;
    cin>>N>>m>>M>>T>>R;
    mb=m;
    t=0;

    while(N>0){
        if(m+T>M){ //최소 맥박에서 운동시 바로 맥박이 초과하는 경우 -1 리턴
            cout<<-1;
                return 0;
        }
        if(mb+T<=M){
            N--;
            mb+=T;
        }else{
            if(mb-R<m){
                mb=m;
            }else{
                mb-=R;   
            }
        }
        t++;
    }
    cout<<t;
}
