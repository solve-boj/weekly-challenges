/*
    바이러스
    https://www.acmicpc.net/problem/2606
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph{
public:
    int size;
    vector<vector<int> > adj;
    
    Graph(): size(0) {}
    Graph(int n): size(n){
        adj.resize(n);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void sortList(){
        for(int i=0; i<size; ++i){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    int bfs(int start){
        int result = 0;
        queue<int> q;
        vector<bool> visit(size);

        fill(visit.begin(), visit.end(), false);
        q.push(start);
        visit[start] = true;

        while(!q.empty()){
            int qsize = q.size();
            for(int i=0; i<qsize; ++i){
                int curr = q.front();
                q.pop();
                for(auto& next: adj[curr]){
                    if(!visit[next]){
                        visit[next] = true;
                        q.push(next);
                        ++result;
                    }
                }
            }
        }

        return result;
    }
};

int main(void){
    int N;
    scanf("%d", &N);

    Graph g(N);
    int M;
    scanf("%d", &M);
    for(int i=0; i<M; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        g.addEdge(a-1, b-1);
    }

    printf("%d", g.bfs(0));
    return 0;
}