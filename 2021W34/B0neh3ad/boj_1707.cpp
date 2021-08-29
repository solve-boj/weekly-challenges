/*
    이분 그래프
    https://www.acmicpc.net/problem/1707
*/
#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
    size_t gsize;
    vector<vector<int>> adj;
    vector<int> bset;
    vector<bool> visited;

    Graph(): gsize(0){}
    Graph(int num): gsize(num){
        adj.resize(num);
        bset.resize(num, -1);
        visited.resize(num, false);
    }
    
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool solution(){
        for(size_t i=0; i<gsize; ++i){
            if(!visited[i]){
                bool temp = bfs(i);
                if(!temp)
                    return false;
            }
        }
        return true;
    }
    
    bool bfs(int start){
        bool res = true;

        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        bset[start] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto& next: adj[curr]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                    bset[next] = 1 - bset[curr];
                }
                else{
                    if(bset[next] == bset[curr]){
                        res = false;
                        break;
                    }
                }
            }
            if(!res)
                break;
        }
        return res;
    }
};

int main(void){
    int K;
    scanf("%d", &K);

    for(size_t t=0; t<K; ++t){
        int V, E;
        scanf("%d %d", &V, &E);

        Graph g(V);
        for(size_t i=0; i<E; ++i){
            int u, v;
            scanf("%d %d", &u, &v);
            if(u != v)
                g.addEdge(u-1, v-1);
        }
        printf(g.solution() ? "YES\n" : "NO\n");
    }
    return 0;
}
/*
    1. 유파로 푸는 문제 아님
    1
    4 4
    1 2
    2 3
    3 4
    4 1

    2. 모든 컴포넌트를 탐색해야 함
    1
    5 4
    1 2
    3 4
    4 5
    5 3
*/