/*
    트리
    https://www.acmicpc.net/problem/4803
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph{
public:
    int gsize;
    vector<vector<int> > adj;
    vector<bool> visited, finished;

    Graph(): gsize(0){}
    Graph(int n): gsize(n){
        adj.resize(n);
        visited.resize(n);
        finished.resize(n);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void sortList(){
        for(int i=0; i<gsize; ++i){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    int countTree(){
        int cnt = 0;
        fill(visited.begin(), visited.end(), false);
        fill(finished.begin(), finished.end(), false);
        for(int i=0; i<gsize; ++i){
            if(!visited[i]){ // 방문하지 않은 정점 존재
                if(!bfs(i)){ ++cnt; } // cycle 없다면 tree 이므로 +1
            }
        }
        return cnt;
    }

private:
    int bfs(int start){
        int flag = 0;
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int next: adj[curr]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
                else if(!finished[next]){
                    flag = 1;
                }
            }
            finished[curr] = true;
        }

        return flag;
    }
};

int main(void){
    int tc = 1;
    while(1){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0){ break; }

        Graph g(n);
        for(int i=0; i<m; ++i){
            int a, b;
            cin >> a >> b;
            g.addEdge(a-1, b-1);
        }
        g.sortList();

        cout << "Case " << tc << ": ";
        int res = g.countTree();
        switch(res){
            case 0:
            cout << "No trees." << endl;
            break;

            case 1:
            cout << "There is one tree." << endl;
            break;

            default:
            cout << "A forest of " << res << " trees." << endl;
            break;
        }

        ++tc;
    }
    return 0;
}