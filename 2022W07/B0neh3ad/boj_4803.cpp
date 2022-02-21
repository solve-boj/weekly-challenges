#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int N;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parent;

    Graph(): N(0){}
    Graph(int n): N(n){
        adj.resize(n);
        visited.resize(n);
        parent.resize(n, -1);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int countTree(){
        fill(visited.begin(), visited.end(), false);

        int ans = 0;
        for(int i=0; i<N; ++i){
            if(!visited[i]){
                // cout << "root: " << i << "\n";
                if(bfs(i)){ ++ans; }
            }
        }

        return ans;
    }

    bool bfs(int root){
        queue<int> q;

        q.push(root);
        visited[root] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            // cout << "curr: " << curr << " | size of adj[curr]: " << adj[curr].size() << "\n";
            for(int next: adj[curr]){
                if(!visited[next]){
                    q.push(next);
                    visited[next] = true;
                    parent[next] = curr;
                }
                // 자식 노드를 방문한 적이 있음
                else if(parent[curr] != next){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(true){
        int n, m;
        cin >> n >> m;
        if(!n && !m){ break; }

        Graph g(n);
        for(int i=0; i<m; ++i){
            int u, v;
            cin >> u >> v;
            g.addEdge(u-1, v-1);
        }

        cout << "Case "<<t++<<": ";
        int ans = g.countTree();
        switch(ans){
            case 0:
            cout << "No trees.\n";
            break;

            case 1:
            cout << "There is one tree.\n";
            break;

            default:
            cout << "A forest of "<<ans<<" trees.\n";
            break;
        }
    }

    return 0;
}