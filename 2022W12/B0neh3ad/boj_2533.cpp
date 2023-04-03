#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n;
vector<bool> visited;
vector<pii> dp;
vector<vector<int>> adj;

void dfs(int curr){
    if(visited[curr]){ return; }

    visited[curr] = true;
    dp[curr].first = 0;
    dp[curr].second = 1;

    bool leaf_flag = true;
    for(auto& next: adj[curr]){
        if(!visited[next]){
            leaf_flag = false;
            dfs(next);
            
            // if next is leaf
            dp[curr].first += dp[next].second;
            dp[curr].second += min(dp[next].first, dp[next].second);
        }
    }
}

int main(void){
    cin >> n;

    adj.resize(n);
    int u, v;
    for(int i=0; i<n-1; ++i){
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    visited.resize(n);
    dp.resize(n);
    
    dfs(0);

    cout << min(dp[0].first, dp[0].second);
    return 0;
}