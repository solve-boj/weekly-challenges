/*
    DFS와 BFS
    https://www.acmicpc.net/problem/1260
*/

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> graph(1001);
stack<int> st;
queue<int> q;
vector<bool> vis(1001, false);

void dfs(int start) {
    int temp;
    st.push(start);
    vis[start] = true;
    while(!st.empty()) {
        temp = st.top();
        printf("%d ", temp);
        st.pop();
        for(int i: graph[temp]) {
            if(!vis[i]) dfs(i);
        }  
    }
}

void bfs(int start) {
    int temp;
    q.push(start);
    vis[start] = true;
    while(!q.empty()) {
        temp = q.front();
        printf("%d ", temp);
        q.pop();
        for(int i: graph[temp]) {
            if(!vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }  
    }
}

int main() {
    int a, b;
    scanf("%d %d %d", &N, &M, &V);
    for(int i=0;i<M;i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1;i<=N;i++) {
        if(!graph[i].empty()) {
            sort(graph[i].begin(), graph[i].end());
        }
    }

    dfs(V);
    fill(vis.begin(), vis.end(), false);
    printf("\n");
    bfs(V);
}