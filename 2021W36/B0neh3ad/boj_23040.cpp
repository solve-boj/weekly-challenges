/*
    누텔라 트리 (Easy)
    https://www.acmicpc.net/problem/23040
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int find(int n, int p[]){
    if(p[n] < 0) { return n; }
    return (p[n] = find(p[n], p));
}

void merge(int lhs, int rhs, int p[]){
    lhs = find(lhs, p);
    rhs = find(rhs, p);
    if(lhs == rhs) return;
    p[lhs] += p[rhs];
    p[rhs] = lhs;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    pii edge[n-1];
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; ++i){
        int u, v;
        cin >> u >> v;
        edge[i] = {u-1, v-1};
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    bool is_black[n] = {0, };

    string nodes;
    cin >> nodes;
    for(int i=0; i<n; ++i){
        if(nodes[i] == 'B'){ is_black[i] = true; }
    }

    int p[n];
    for(int i=0; i<n; ++i){ p[i] = -1; }
    for(int i=0; i<n-1; ++i){
        int u = edge[i].first;
        int v = edge[i].second;
        if(!is_black[u] && !is_black[v]){
            merge(u, v, p);
        }
    }
    

    long long answer = 0;
    for(int i=0; i<n; ++i){
        if(is_black[i]){
            for(auto& red_root: adj[i]){
                if(!is_black[red_root])
                    answer -= p[find(red_root, p)];
            }
        }
    }

    cout << answer;
    return 0;
}
/*
    반례 몇 개

    6
    1 2
    1 3
    1 4
    1 5
    1 6
    BBBBBB

    2
    1 2
    RR
*/