/*
    The Mountain of Gold?
    https://www.acmicpc.net/problem/10360
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long, int> P;
const long long INF = 2e9;

int main(void){
    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; ++t){
        int N, M;
        scanf("%d %d", &N, &M);

        vector<P> adj[N];
        int A, B, C;
        for(int i=0; i<M; ++i){
            scanf("%d %d %d", &A, &B, &C);
            adj[A].push_back(P(C, B));
        }

        long long dist[N];
        bool isPossible = false;
        bool isInsideCycle[N];

        fill(dist, dist+N, INF);
        fill(isInsideCycle, isInsideCycle+N, false);
        dist[0] = 0;
        for(int i=0; (i<N && !isPossible); ++i){
            for(int curr=0; (curr<N && !isPossible); ++curr){
                for(auto& p: adj[curr]){
                    int d = p.first;
                    int next = p.second;
                    if(dist[curr] < INF && dist[next] > dist[curr] + d){
                        dist[next] = dist[curr] + d;
                        if(i == N-1){ isInsideCycle[next] = isInsideCycle[curr] = true; }
                    }
                }
            }
        }

        for(int i=0; (i<N && !isPossible); ++i){
            if(isInsideCycle[i]){
                queue<int> q;
                bool visited[N];
                fill(visited, visited+N, false);

                visited[i] = true;
                q.push(i);

                while(!isPossible && !q.empty()){
                    int curr = q.front();
                    q.pop();

                    for(auto& p: adj[curr]){
                        int next = p.second;
                        if(!visited[next]){
                            if(next == 0){
                                isPossible = true;
                                break;
                            }
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                }
            }
        }

        printf("Case #%d: %s\n", t, isPossible ? "possible" : "not possible");
    }
    return 0;
}
/*
    0에서 시작해서 0으로 돌아갔을 때 최단 거리가 0보다 작은가?
    
    [혹시라도 '틀렸습니다'를 받고 이 소스 코드를 보고 계시는 분들께...]
    1) minus Cycle 존재 여부를 체크하셨는지
    2) Cycle 구성 node에서 시작점으로 돌아갈 수 있는지 여부를 체크하셨는지
    확인해보시기 바랍니다.
*/