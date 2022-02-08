#include <bits/stdc++.h>
using namespace std;

int cnt;

class Graph{
public:
    int size;
    vector<vector<int>> adj;
    vector<bool> visited;

    Graph(): size(0){}
    Graph(int n): size(n){
        adj.resize(n+1);
        visited.resize(n+1);
    }

    void addEdge(int u, int v){
        if(!count(adj[u].begin(), adj[u].end(), v)){
            adj[u].push_back(v);
        }
        if(!count(adj[v].begin(), adj[v].end(), u)){
            adj[v].push_back(u);
        }
    }

    void sortList(){
        for(int i=1; i<=size; ++i){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    void bfs(int start){
        fill(visited.begin(), visited.end(), false);

        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int next: adj[curr]){
                if(!visited[next]){
                    visited[next] = true;
                    ++cnt;
                    q.push(next);
                }
            }
        }
    }
};

int main(void){

    int n, e;
    cin >> n >> e;

    Graph g(n);
    for(int i=0; i<e; ++i){
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.sortList();
    g.bfs(1);
    cout << cnt;

    return 0;
}