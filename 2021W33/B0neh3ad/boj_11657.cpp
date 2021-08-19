/*
    타임머신
    https://www.acmicpc.net/problem/11657
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const long long INF = 1e18;

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<P> adj[500];

    int A, B, C;
    for(int i=0; i<M; ++i){
        scanf("%d %d %d", &A, &B, &C);
        adj[A-1].push_back(P(C, B-1));
    }

    long long dist[500];
    bool minusCycle = false;
    fill(dist, dist+N, INF);
    dist[0] = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            for(auto &p: adj[j]){
                int d = p.first;
                int next = p.second;
                if(dist[j] != INF && dist[next] > dist[j] + d){
                    dist[next] = dist[j] + d;
                    if(i == N-1){ minusCycle = true; }
                }
            }
        }
    }

    if(minusCycle){ printf("-1\n"); }
    else{
        for(int i=1; i<N; ++i)
            printf("%lld\n", dist[i]!=INF ? dist[i] : -1);
    }
    return 0;
}