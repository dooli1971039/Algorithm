#include <stdio.h>
#include <stdlib.h>

#define min(x, y) (x) < (y) ? (x) : (y) //min 함수 정의
const int INF=1e7*2; //최대 n-1개의 간선을 지나게 됨

int** fillGraph(int n, int** fares, int fares_rows){ // ex는 테스트케이스 개수
    // 1. nxn 배열의 모든 원소를 INF로 채워넣는다. (자기 자신은 0으로)
    int** graph=(int**)malloc(sizeof(int*)*(n+1));
    for(int i=1;i<=n;i++){
        graph[i]=(int*)malloc(sizeof(int)*(n+1));
        for(int j=1;j<=n;j++)
            graph[i][j]=INF;
        
        graph[i][i]=0; //자기 자신과의 비용은 0
    }
    
    // 2. 주어진 입력값으로 초기화를 합니다.
		for(int i=0;i<fares_rows;i++){
        // a->b, b->a의 비용이 같은 양방향 그래프
        graph[fares[i][0]][fares[i][1]]=fares[i][2];
        graph[fares[i][1]][fares[i][0]]=fares[i][2];
    }
    
    return graph;
}

// 3. 플로이드-워셜
void floydWarshall(int** graph, int n){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                //k 지점을 지나는 것이 더 저렴할 경우 업데이트
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]); 
}
// _msize()가 지원되지 않아, 인자로 fares의 행 길이와 열 길이를 인자로 넘겨줍니다.(fares_rows, fares_cols)
int solution(int n, int s, int a, int b, int** fares, int fares_rows, int fares_cols, int lay){
    int answer=INF;
    int** graph=fillGraph(n, fares, fares_rows); //초기화 (ex는 테스트케이스 개수)
    floydWarshall(graph,n); // 플로이드-워셜 적용
    
  // 4. 최소 비용 계산
	// lay는 경유지
	for(int i=1;i<=n;i++){
	    answer=min(answer,graph[s][lay]+graph[lay][i]+graph[i][a]+graph[i][b]);
	}
	
	return answer;
}

int main() {
	int n, s, a, b, c;
	scanf("%d %d %d %d %d", &n, &s, &a, &b, &c);

	// 테스트 케이스 개수 : 9
	int ex=9;
	int** fares = (int**)malloc(sizeof(int*) * ex);
	for (int i = 0; i < ex; i++) {
		fares[i] = (int*)malloc(sizeof(int) * 3);
		for (int j = 0; j < 3; j++)
			scanf("%d", &fares[i][j]);
	}

	int ans = solution(n, s, a, b, fares,9,3, c);
	printf("%d", ans);
}
