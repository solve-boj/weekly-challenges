#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<vector<int>> adj;

int dp[100000];
bool visited[100000];

int dfs(int curr){
    dp[curr] = 1;
    visited[curr] = true;

    for(auto& next: adj[curr]){
        if(!visited[next]){
            dp[curr] += dfs(next);
        }
    }

    return dp[curr];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> q;
    adj.resize(n);

    int u, v;
    for(int i=0; i<n-1; ++i){
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs(--r);

    int sr;
    for(int i=0; i<q; ++i){
        cin >> sr;
        cout << dp[--sr] << '\n';
    }
    
    return 0;
}