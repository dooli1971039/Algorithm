//합승 택시 요금
#include <iostream>
#include <vector>
#define INF 1e7
int A[201][201]={0,};
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    // 1. nxn 배열의 모든 원소를 INF로 채워 넣는다. (자기 자신은 0으로)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            A[i][j]=INF;
        }
        A[i][i]=0; //자기 자신과의 비용은 0
    }
    
    // 2. 주어진 입력값으로 초기화를 합니다.
    for(int i=0;i<fares.size();i++){
        A[fares[i][0]][fares[i][1]]=fares[i][2];
        A[fares[i][1]][fares[i][0]]=fares[i][2];
    }
    
    // 3. 플로이드-워셜을 적용
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]); //k 지점을 지나는 것이 더 저렴할 경우 업데이트
            }
        }
    }
    
    // 4. 최소 비용 계산
    for(int i=1;i<=n;i++){
        answer=min(answer,A[s][i]+A[i][a]+A[i][b]);
    }
    
    return answer;
}