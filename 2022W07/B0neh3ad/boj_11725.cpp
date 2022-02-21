#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int N;
    vector<vector<int>> adj;
    vector<int> parent;

    Graph(): N(0){}
    Graph(int n): N(n){
        adj.resize(n);
        parent.resize(n, -1);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findParent(int root){
        bool visited[N] = {0, };
        queue<int> q;

        q.push(root);
        visited[root] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int next: adj[curr]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                    parent[next] = curr;
                }
            }
        }
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Graph g(n);
    for(int i=0; i<n-1; ++i){
        int u, v;
        cin >> u >> v;
        g.addEdge(u-1, v-1);
    }

    g.findParent(0);
    
    for(int i=1; i<n; ++i){
        cout << g.parent[i]+1 << '\n';
    }
    return 0;
}