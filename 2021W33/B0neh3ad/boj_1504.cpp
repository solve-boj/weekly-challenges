/*
    특정한 최단 경로
    https://www.acmicpc.net/problem/1504
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> P;
const int MAX_V = 801;
const int INF = 100000000;

int N, E;
int a, b, c;
int v1, v2;
int start_path[2], end_path[2], mid_path;

std::vector<P> adj[MAX_V];

void dijkstra(int s){
    int dist[MAX_V];
    int pre[MAX_V];
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    std::fill(dist, dist+MAX_V, INF);
    std::fill(pre, pre+MAX_V, -1);

    dist[s] = 0;
    pq.push(P(0, s));

    while(!pq.empty()){
        long long cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(cost > dist[curr]) continue; // 이거 그동안 break로 쓰고 있었네...?

        for(auto& p: adj[curr]){
            int d = p.first;
            int next = p.second;
            if(dist[next] > dist[curr] + d){ // 여기서 int형으로 안 바꿔서 오류난 듯... 그냥 0 하나 뺄 걸... 이 아니네?
                dist[next] = dist[curr] + d;
                pre[next] = curr;
                pq.push(P(dist[next], next));
            }
        }
    }

    if(s == 0){ start_path[0] = dist[v1], start_path[1] = dist[v2]; }
    if(s == N){ end_path[0] = dist[v1], end_path[1] = dist[v2]; }
    if(s == v1){ mid_path = dist[v2]; }
}

int main(void){
    scanf("%d %d", &N, &E);
    --N;

    for(int i=0; i<E; ++i){
        scanf("%d %d %d", &a, &b, &c);
        adj[a-1].push_back(P(c, b-1));
        adj[b-1].push_back(P(c, a-1));
    }

    scanf("%d %d", &v1, &v2);
    --v1; --v2;
    
    int ans = INF;

    dijkstra(0);
    dijkstra(N);
    dijkstra(v1);
    ans = mid_path + std::min(start_path[0]+end_path[1], start_path[1]+end_path[0]);

    if(ans >= INF || ans < 0){ printf("-1"); }
    else{ printf("%d", ans); }
    return 0;
}
/*
    다익스트라 응용 문제.
    [1,v1][1,v2][v1,N][v2,N][v1,v2]의 5개 구간에 대한 최단 경로 탐색 후
    적절히 조합해서 푸는 문제.

    1) 혹시 모른다. 오버플로우 났을지... 그래서 일단 자료형을 바꿔줬다.
    2) 다익스트라 5번 돌림 -> 3번 돌림으로 성능 개선

    모든 반례에 대해 답이 다 맞아떨어졌는데.. 이상하게 ideone으로 돌리면 답이 안 맞는 걸 확인했다.
    약 1시간 가량의 삽질 끝에 c의 자료형이 long long이 아닌데 %lld로 입력을 받아 생긴 문제임을 확인했다.

    ㅈㄴ 어이없네 ㅋㅋ continue를 break로 써서 계속 틀리고 있었음 ㅅㅂ
*/ 