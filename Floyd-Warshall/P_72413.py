import sys
#본 시험에서는 solution 코드와 별도로 필요한 함수만 작성합니다.

INF = 1e7 #최대 n-1개의 간선을 지나게 됨

def fillGraph(n,fares):
    # 1. nxn 배열의 모든 원소를 INF로 채워 넣는다.
    graph=[[INF]*(n+1) for _ in range(n+1)]
    
    for i in range(1,n+1):
        graph[i][i]=0 # 자기 자신과의 비용은 0
        
    # 2. 주어진 입력값으로 초기화를 합니다
    for u,v,w in fares:
        # a->b, b->a의 비용이 같은 양방향 그래프
        graph[u][v]=w
        graph[v][u]=w
        
    return graph

# 3. 플로이드-워셜
def floydWarshall(graph,n):
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                # k 지점을 지나는 것이 더 저렴할 경우 업데이트
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]); 

def solution(n, s, a, b, fares, lay):
#들여쓰기에 주의하면서 필요한 코드를 작성하세요
    answer = INF
    graph = fillGraph(n,fares) # 초기화
    floydWarshall(graph,n) # 플로이드-워셜 적용
	
    # 4. 최소 비용 계산
    # lay는 경유지
    for i in range(1,n+1):
        answer=min(answer, graph[s][lay]+graph[lay][i]+graph[i][a]+graph[i][b])
 
    return answer

if __name__ == "__main__":
    input = sys.stdin.readline
    n, s, a, b, c = map(int, input().split())

    # 테스트 케이스 개수 : 9
    i = 9;
    fares=[list(map(int, input().split())) for _ in range(i)]
    answer = solution(n, s, a, b, fares, c)
    print(answer)