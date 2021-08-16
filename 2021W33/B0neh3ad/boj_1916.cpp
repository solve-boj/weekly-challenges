/*
    최소비용 구하기
    https://www.acmicpc.net/problem/1916
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_V = 1000;
const int INF = 1000000000;
typedef pair<int, int> P;

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    vector<P> adj[MAX_V];
    int u, v, w;
    for(int i=0; i<M; ++i){
        scanf("%d %d %d", &u, &v, &w);
        adj[u-1].push_back(P(w, v-1));
    }

    int s, e;
    scanf("%d %d", &s, &e);
    --s; --e;

    int dist[MAX_V];
    fill(dist, dist+MAX_V, INF);
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[s] = 0;
    pq.push(P(0, s));
    while(!pq.empty()){
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if(cost > dist[curr]) continue;

        for(auto& p: adj[curr]){
            int d = p.first, next = p.second;
            if(dist[next] > dist[curr] + d){
                dist[next] = dist[curr] + d;
                pq.push(P(dist[next], next));
            }
        }
    }

    printf("%d", dist[e]);
    return 0;
}
/*
    최소 힙이라는 점 잘 기억하자
*/