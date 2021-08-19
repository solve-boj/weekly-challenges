/*
    전력난
    https://www.acmicpc.net/problem/6497
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
    while(true){
        int m, n;
        scanf("%d %d", &m, &n);
        if(!m && !n){ break; }

        vector<P> adj;
        int x, y, z;
        int answer = 0;
        for(int i=0; i<n; ++i){
            scanf("%d %d %d", &x, &y, &z);
            answer += z;
            adj.push_back(P(z, {x, y}));
        }
        sort(adj.begin(), adj.end());

        int parent[m];
        int cnt = 0;
        for(int i=0; i<m; ++i){ parent[i] = i; }
        for(auto& edge: adj){
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if(merge(u, v, parent)){
                answer -= w;
                if(++cnt == m-1){ break; }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
/*
    스패닝 트리는 애초에 '연결 여부'가 핵심이므로 방향은 안 중요함.
    문제랑 관련된 건 아니지만 혹여나 헷갈릴까봐 적어둡니당
*/