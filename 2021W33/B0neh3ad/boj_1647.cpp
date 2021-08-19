/*
    도시 분할 계획
    https://www.acmicpc.net/problem/1647
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, pair<int, int> > P;

int find(int num, int p[]){
    if(num == p[num]){ return num; }
    return (p[num] = find(p[num], p));
}

bool merge(int lhs, int rhs, int p[]){
    lhs = find(lhs, p);
    rhs = find(rhs, p);
    if(lhs == rhs){ return false; }
    p[rhs] = lhs;
    return true;
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    int parent[n];
    for(int i=0; i<n; ++i){ parent[i] = i; }
    P adj[m];    
    int a, b, c;
    for(int i=0; i<m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        adj[i] = P(c, {a-1, b-1});
    }

    sort(adj, adj+m);
    int min_cost = 0, cnt = 0;
    if(n > 2){
        for(auto& edge: adj){
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if(merge(u, v, parent)){
                min_cost += w;
                if(++cnt == n-2){ break; }
            }
        }
    }

    printf("%d", min_cost);
    return 0;
}
/*
    일단 무지성으로 최소 스패닝 트리 만들고,
    거기서 간선 하나만 딱 끊으면 바로 2개의 마을 됨.
    (만약 그렇지 않다면 최소 스패닝 트리가 아니었던 것)
    그리고 각각의 마을은 최소 스패닝 트리의 조건을 만족.
    O(M+N) + O(MlogM) + O(Mlog*M) = O(MlogM)
*/