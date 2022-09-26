import java.io.*;
import java.util.*;

//본 시험에서는 solution 코드와 별도로 필요한 함수만 작성합니다.
public class Main {
    static int INF =100_000_000; //최대 n-1개의 간선을 지나게 됨

    public static int[][] fillGraph(int n, int[][] fares){
        int [][] graph=new int[n+1][n+1];

        // 1. nxn 배열의 모든 원소를 INF로 채워 넣는다. (자기 자신은 0으로)
        for(int i=1;i<=n;i++){
            Arrays.fill(graph[i],INF);
            graph[i][i]=0; //자기 자신과의 비용은 0
        }

        // 2. 주어진 입력값으로 초기화를 합니다.
        for(int i=0;i<fares.length;i++){
            // a->b, b->a의 비용이 같은 양방향 그래프
            graph[fares[i][0]][fares[i][1]]=fares[i][2];
            graph[fares[i][1]][fares[i][0]]=fares[i][2];
        }

        return graph;
    }

    // 3. 플로이드-워셜
    public static void floydWarshall(int[][] graph, int n){
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    //k 지점을 지나는 것이 더 저렴할 경우 업데이트
                    graph[i][j]=Math.min(graph[i][j],graph[i][k]+graph[k][j]);   
    }

	public static int solution(int n, int s, int a, int b, int[][] fares, int lay) {
		int answer = INF;
        int[][] graph=fillGraph(n,fares); //초기화

        floydWarshall(graph,n);

        // 4. 최소 비용 계산
        // lay는 경유지
        for(int i=1;i<=n;i++){
            answer=Math.min(answer,graph[s][lay]+graph[lay][i]+graph[i][a]+graph[i][b]);
        }
		
		return answer;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		int n = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());

		// 테스트 케이스 개수 : 9
		int i = 9;
		int[][] fares = new int[i][3];
		while (i-- > 0) {
			str = br.readLine();
			st = new StringTokenizer(str);
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());

			fares[i] = new int[] { u, v, w };
		}

		int answer = solution(n, s, a, b, fares, c);
		System.out.println(answer);
	}
}