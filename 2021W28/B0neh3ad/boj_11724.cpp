/*
    연결 요소의 개수
    https://www.acmicpc.net/problem/11724
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Graph{
public:
    int gsize;
    vector<vector<int> > adj;
    vector<bool> visited;

    Graph() : gsize(0){}
    Graph(int n) : gsize(n){
        adj.resize(n);
        visited.resize(n);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void sortList(){
        for(int i=0; i<gsize; i++){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    int beginDfs(){
        int components = 0;
        for(int i=0; i<gsize; i++){
            if(!visited[i]){
                components++;
                dfs(i);
            }
        }
        return components;
    }

private:
    void dfs(int curr){
        visited[curr] = true;
        for(int next: adj[curr]){
            if(!visited[next]){
                dfs(next);
            }
        }
    }
};

int main(void){
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u-1, v-1);
    }

    cout << g.beginDfs();
    return 0;
}