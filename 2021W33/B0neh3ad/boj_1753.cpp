/*
    최단 경로
    https://www.acmicpc.net/problem/1753
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_V = 20000;
const int INF = 1000000000;
typedef pair<int, int> P;

int main(void){
    // input
    int V, E, K;
    scanf("%d %d %d", &V, &E, &K);
    --K;
    int u, v, w;
    vector<P> adj[MAX_V];
    for(int i=0; i<E; ++i){
        scanf("%d %d %d", &u, &v, &w);
        adj[u-1].push_back(P(w, v-1));
    }

    // init set
    int dist[MAX_V];
    fill(dist, dist+MAX_V, INF);
    bool visited[MAX_V] = {0};
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[K] = 0;
    pq.push(P(0, K));

    // Dijkstar
    while(!pq.empty()){
        int curr;
        do{
            curr = pq.top().second;
            pq.pop();
        }while(visited[curr] && !pq.empty());
        if(visited[curr]) break;

        visited[curr] = true;
        for(auto& p: adj[curr]){
            int next = p.second, d = p.first;
            if(dist[next] > dist[curr] + d){
                dist[next] = dist[curr] + d;
                pq.push(P(dist[next], next));
            }
        }
    }

    // output
    for(int i=0; i<V; ++i){
        if(dist[i] == INF){ printf("INF\n"); }
        else{ printf("%d\n", dist[i]); }
    }
    return 0;
}
/*
    다익스트라..
*/