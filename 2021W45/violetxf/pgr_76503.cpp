/*
    모두 0으로 만들기
    https://programmers.co.kr/learn/courses/30/lessons/76503
*/
#include <string>
#include <vector>

using namespace std;
long long value[300001];
bool visited[300001]={false};
long long total_cost = 0;
vector<vector<int>> adj;
long long dfs(int);
long long solution(vector<int> a, vector<vector<int>> edges) {
    for(int i=0;i<a.size();i++){
        value[i] = a[i];
    }
    adj.resize(a.size());
    for(auto edge: edges){
        int a = edge[0];
        int b = edge[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(dfs(0)!=0)return -1;
    return total_cost;
}
long long dfs(int point){
    visited[point] = true;
    for(int i=0;i<adj[point].size();i++){
        int next = adj[point][i];
        if(!visited[next]){
            value[point] += dfs(next);
        }
    }
    total_cost += abs(value[point]);
    return value[point];
}