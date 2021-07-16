/*
    텀 프로젝트
    https://www.acmicpc.net/problem/9466
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
public:
    int gsize;
    vector<vector<int> > adj;
    vector<bool> visited;
    vector<bool> finished;
    vector<int> visit_lst;

    Graph(): gsize(0){}
    Graph(int n): gsize(n){
        adj.resize(n);
        visited.resize(n);
        finished.resize(n);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void sortList(){
        for(int i=0; i<gsize; i++){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    int solution(){
        fill(visited.begin(), visited.end(), false);
        fill(finished.begin(), finished.end(), false);
        
        int sum_cycles = 0;
        for(int i=0; i<gsize; i++){
            if(!visited[i]){
                visit_lst.push_back(i);
                sum_cycles += dfs(i);
                // cout << "sum_cycles: " << sum_cycles << endl;
            }
        }
        
        return gsize - sum_cycles;
    }

    int dfs(int curr){
        int cycles = 0;
        visited[curr] = true;
        for(int next: adj[curr]){
            if(!finished[next]){
                if(!visited[next]){ // cycle에 속해있지 않거나 cycle의 마지막 탐색 노드가 아닌 경우
                    visit_lst.push_back(next);
                    cycles += dfs(next);
                    visit_lst.pop_back();
                }
                else{ // cycle의 마지막 탐색 노드인 경우
                    int i=1;
                    while(visit_lst[visit_lst.size() - i] != next){ i++; }
                    cycles += i;
                }
            }
        }
        finished[curr] = true;
        return cycles;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        Graph g(n);
        int temp;
        for(int j=0; j<n; j++){
            cin >> temp;
            g.addEdge(j, temp-1);
        }

        cout << g.solution() << '\n';
    }
    return 0;
}