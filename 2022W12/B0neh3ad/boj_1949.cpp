#include <bits/stdc++.h>
using namespace std;

int n, nodes[10000], dp[10000][2];
bool visited[10000];
vector<vector<int>> adj;

void dfs(int curr){
    if(visited[curr]){ return; }

    visited[curr] = true;
    dp[curr][1] = nodes[curr];

    for(auto& next: adj[curr]){
        if(!visited[next]){
            dfs(next);
            dp[curr][0] += max(dp[next][0], dp[next][1]);
            dp[curr][1] += dp[next][0];
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> nodes[i];
    }

    int u, v;
    adj.resize(n);
    for(int i=0; i<n-1; ++i){
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs(0);
    
    cout << max(dp[0][0], dp[0][1]);
    return 0;
}