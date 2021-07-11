/*
    가장 먼 노드
    https://programmers.co.kr/learn/courses/30/lessons/49189
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Graph{
public:
    int nodes;
    vector<vector<int> > adj;
    vector<int> visited;
    
    // 생성자
    Graph(): nodes(0){}
    Graph(int num): nodes(num){
        adj.resize(num);
        visited.resize(num);
    }

    void addEdge(int u, int v){ // 엣지 추가
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    void sortList(){ // 노드 별 인접 리스트를 정렬
        for(int i=0; i<adj.size(); i++){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    int bfs(int start){ // bfs 탐색 후 가장 먼 거리 return
        queue<int> Q;

        fill(visited.begin(), visited.end(), -1);
        Q.push(start);
        visited[start] = 0;

        int level = 0;
        while(!Q.empty()){
            int qsize = Q.size();

            for(int i=0; i<qsize; i++){
                int curr = Q.front();
                Q.pop();

                for(int next: adj[curr]){
                    if(visited[next] < 0){
                        visited[next] = level + 1;
                        Q.push(next);
                    }
                }
            }
            level++;
        }

        return count(visited.begin(), visited.end(), level-1);
    }
};

int solution(int n, vector<vector<int> > edge){
    Graph g(n);
    int answer = 0;

    for(int i=0; i<edge.size(); i++){ g.addEdge(edge[i][0], edge[i][1]); }
    g.sortList();
    answer = g.bfs(0);
    return answer;
}