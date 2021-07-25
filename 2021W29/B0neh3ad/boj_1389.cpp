/*
    케빈 베이컨의 6단계 법칙
    https://www.acmicpc.net/problem/1389
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Graph{
public:
    int size;
    vector<vector<int> > adj;
    vector<int> visited;

    // 생성자
    Graph(int n): size(n){
        adj.resize(n);
        visited.resize(n);
    }

    void addEdge(int u, int v){ // 간선 추가
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void sortList(){
        for(int i=0; i<size; ++i)
            sort(adj[i].begin(), adj[i].end());
    }

    int bfs(int start){
        // 단계 기록 배열 초기 세팅
        fill(visited.begin(), visited.end(), -1);

        // 큐 초기 세팅
        queue<int> q;
        q.push(start);
        visited[start] = 0;

        int curr;
        int bacon = 0;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            for(int next: adj[curr]){
                if(visited[next] == -1){
                    visited[next] = visited[curr] + 1;
                    bacon += visited[next];
                    q.push(next);
                }
            }
        }

        return bacon;
    }
};

int main(void){
    int n, m;
    cin >> n >> m;

    Graph people(n);
    int a, b;
    for(int i=0; i<m; ++i){
        cin >> a >> b;
        people.addEdge(a-1, b-1);
    }

    int ans = 1, min_bacon = 10000;
    for(int i=0; i<n; ++i){
        int curr_bacon = people.bfs(i);
        if(min_bacon > curr_bacon){
            min_bacon = curr_bacon;
            ans = i+1;
        }
    }

    cout << ans;
    return 0;
}