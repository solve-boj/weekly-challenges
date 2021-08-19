/*
    네트워크 연결
    https://www.acmicpc.net/problem/1922
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int> > P;

int find(int num, int parent[]){
    if(num == parent[num]){ return num; }
    return (parent[num] = find(parent[num], parent));
}

void merge(int lhs, int rhs, int parent[]){
    lhs = find(lhs, parent);
    rhs = find(rhs, parent);
    if(lhs == rhs){ return; }
    parent[rhs] = lhs;
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    
    int p[N];
    for(int i=0; i<N; ++i){ p[i] = i; }

    vector<P> adj;
    int a, b, c;
    for(int i=0; i<M; ++i){
        scanf("%d %d %d", &a, &b, &c);
        if(a != b){
            adj.push_back(P(c, {a-1, b-1}));
        }
    }

    sort(adj.begin(), adj.end());

    int ans = 0, cnt = 0;
    for(auto& edge: adj){
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u, p) != find(v, p)){
            ans += w;
            merge(u, v, p);
            ++cnt;
        }
        if(cnt == N-1){ break; }
    }

    printf("%d", ans);
    return 0;
}