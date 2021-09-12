/*
    소방차
    https://www.algospot.com/judge/problem/read/FIRETRUCKS
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int MAX_V = 1000;
const int INF = 1e8;

int main(void){
    int C;
    scanf("%d", &C);

    for(int c=0; c<C; ++c){
        int V, E, n, m;
        scanf("%d %d %d %d", &V, &E, &n, &m);

        vector<P> adj[MAX_V];
        for(int i=0; i<E; ++i){
            int a, b, t;
            scanf("%d %d %d", &a, &b, &t);
            adj[a-1].push_back(P(t, b-1));
            adj[b-1].push_back(P(t, a-1));
        }

        int fire[MAX_V], sta[MAX_V];
        for(int i=0; i<n; ++i){ scanf("%d", &fire[i]); --fire[i]; }
        for(int i=0; i<m; ++i){ scanf("%d", &sta[i]); --sta[i]; }

        for(int i=0; i<m-1; ++i){
            for(int j=i+1; j<m; ++j){
                adj[sta[i]].push_back(P(0, sta[j]));
                adj[sta[j]].push_back(P(0, sta[i]));
            }
        }

        int dist[MAX_V];
        fill(dist, dist+V, INF);
        priority_queue<P, vector<P>, greater<P> > pq;

        dist[sta[0]] = 0;
        pq.push(P(0, sta[0]));
        while(!pq.empty()){
            int cost = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if(cost > dist[curr]) continue;

            for(auto& p: adj[curr]){
                int d = p.first;
                int next = p.second;
                if(dist[next] > dist[curr] + d){
                    dist[next] = dist[curr] + d;
                    pq.push(P(dist[next], next));
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; ++i){
            ans += dist[fire[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}