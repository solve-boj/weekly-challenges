#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pil = pair<int, ll>;

class Tree{
public:
    int n;
    vector<vector<pil>> adj;
    vector<bool> visited;

    Tree(): n(0){}
    Tree(int num): n(num){
        adj.resize(num);
        visited.resize(num);
    } 

    void addEdge(int u, int v, ll dist){
        adj[u].push_back(pil(v, dist));
        adj[v].push_back(pil(u, dist));
    }

    void sortEdge(){
        for(int i=0; i<n; ++i){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    pil beginDfs(int s){
        fill(visited.begin(), visited.end(), false);
        return dfs(s);
    }

private:
    pil dfs(int curr){
        visited[curr] = true;

        int max_point = curr;
        ll max_dist = 0;
        for(pil p: adj[curr]){
            int next = p.first;
            if(!visited[next]){
                ll dist = p.second;

                pil temp = dfs(next);
                dist += temp.second;

                if(max_dist < dist){
                    max_dist = dist;
                    max_point = temp.first;
                }
            }
        }

        return pil(max_point, max_dist);
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    cin >> v;

    Tree t(v);
    for(int i=0; i<v; ++i){
        int a;
        cin >> a;
        while(true){
            int b;
            cin >> b;
            if(b == -1){ break; }

            ll w;
            cin >> w;
            t.addEdge(a-1, b-1, w);
        }
    }

    int l_side = t.beginDfs(0).first;
    ll res = t.beginDfs(l_side).second;
    cout << res;

    return 0;
}