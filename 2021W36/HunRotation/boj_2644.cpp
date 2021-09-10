/*
    촌수계산
    https://www.acmicpc.net/problem/2644
*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, a, b;
vector<vector<int>> graph(101);
vector<bool> vis(101, false);
queue<pair<int, int>> q;


int main() {
    int tx, ty, ans = -1;
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        scanf("%d %d", &tx, &ty);
        graph[tx].push_back(ty);
        graph[ty].push_back(tx);
    }
    q.push({a, 0});
    vis[a] = true;
    int cur, level;

    while(!q.empty()) {
        cur = q.front().first;
        level = q.front().second;
        q.pop();
        if(cur == b) {
            ans = level;
        }

        for(int i=0;i<graph[cur].size();i++) {
            if(!vis[graph[cur][i]]) {
                q.push({graph[cur][i], level+1});
                vis[graph[cur][i]] = true;
            }
        }
    }

    printf("%d", ans);
}

// keyword: BFS
// 시간복잡도: O(M)
/*
idea: 간단한 BFS, 큐를 활용함
*/