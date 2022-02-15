#include <bits/stdc++.h>
using namespace std;

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

    void sortEdge(){
        for(int i=1; i<=size; ++i){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    void bfs(int start){
        queue<int> q;
        fill(visited.begin(), visited.end(), false);

        visited[start] = true;
        cout << start << " ";
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int next: adj[curr]){
                if(!visited[next]){
                    visited[next] = true;
                    cout << next << " ";
                    q.push(next);
                }
            }
        }
        cout << endl;
    }

    void beginDfs(int start){
        fill(visited.begin(), visited.end(), false);

        dfs(start);
        cout << endl;
    }

private:
    void dfs(int curr){
        visited[curr] = true;
        cout << curr << " ";

        for(int next: adj[curr]){
            if(!visited[next]){
                visited[next] = true;
                dfs(next);
            }
        }
    }
};

int main(void){
    int n, m, v;
    cin >> n >> m >> v;

    Graph g(n);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.sortEdge();

    g.beginDfs(v);
    g.bfs(v);

    return 0;
}