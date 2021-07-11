/*
    가장 먼 노드
    https://programmers.co.kr/learn/courses/30/lessons/49189
*/
#include <bits/stdc++.h>

using namespace std;

int solution(int N, vector<vector<int>> edges) {
    vector<list<size_t>> E(N);
    for(auto& edge:edges){
        E[edge[0]-1].push_back(edge[1]-1);
        E[edge[1]-1].push_back(edge[0]-1);
    }
    
    vector<size_t> dist(N, 0);
    queue<size_t> q;
    dist[0] = 1;
    q.emplace(0);
    
    while(!q.empty()){
        size_t v = q.front();
        q.pop();
        
        for(auto& next:E[v])
            if(!dist[next]){
                dist[next] = dist[v] + 1;
                q.emplace(next);
            }
    }
    
    size_t farthest_dist = dist[1];
    size_t farthest_count = 1;
    for(size_t i=2; i!=N; ++i)
        if(dist[i] == farthest_dist)
            ++farthest_count;
        else if(dist[i] > farthest_dist){
            farthest_dist = dist[i];
            farthest_count = 1;
        }
    
    return farthest_count;
}