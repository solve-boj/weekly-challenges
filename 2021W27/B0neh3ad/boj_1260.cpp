/*
    DFS와 BFS
    https://www.acmicpc.net/problem/1260
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph{
public:
    int size;
    vector<vector<int> > adj;
    vector<bool> visited;

    Graph(): size(0){}
    Graph(int n): size(n){
        adj.resize(n+1);
        visited.resize(n+1);
    }

    void addEdge(int u, int v){
        if(count(adj[u].begin(), adj[u].end(), v) == 0){ adj[u].push_back(v); }
        if(count(adj[v].begin(), adj[v].end(), u) == 0){ adj[v].push_back(u); }
    }

    void sortList(){
        for(int i=1; i<=size; i++){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    void bfs(int start){
        queue<int> Q;

        fill(visited.begin(), visited.end(), false);

        visited[start] = true;
        cout << start << " ";
        Q.push(start);

        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();

            for(int next: adj[curr]){
                if(!visited[next]){
                    visited[next] = true;
                    cout << next << " ";
                    Q.push(next);
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
            if(!visited[next]){ dfs(next); }
        }
    }
};

int main(){
    int n, m, v;
    cin >> n >> m >> v;

    Graph g(n);
    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        g.addEdge(x, y);
    }
    g.sortList();

    g.beginDfs(v);
    g.bfs(v);

    return 0;
}