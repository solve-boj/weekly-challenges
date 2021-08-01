/*
    트리의 부모 찾기
    https://www.acmicpc.net/problem/11725
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

class Tree{
public:
    int tsize;
    std::vector<std::vector<int> > adj;
    std::vector<int> parent;

    Tree(): tsize(0){}
    Tree(int n): tsize(n){
        adj.resize(n);
        parent.resize(n, -1);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void selectRoot(int rt){
        std::queue<int> q;
        std::vector<bool> visit(tsize, false);

        visit[rt] = true;
        q.push(rt);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int next: adj[curr]){
                if(!visit[next]){
                    visit[next] = true;
                    parent[next] = curr;
                    q.push(next);
                }
            }
        }
    }
};

int main(void){
    int N;
    scanf("%d", &N);

    Tree t(N);
    for(int i=0; i<N-1; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        t.addEdge(a-1, b-1);
    }

    t.selectRoot(0);

    for(int i=1; i<N; ++i)
        printf("%d\n", t.parent[i]+1);

    return 0;
}