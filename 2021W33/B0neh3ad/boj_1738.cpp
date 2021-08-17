/*
    골목길
    https://www.acmicpc.net/problem/1738
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<long long, int> P;
const long long INF = 1e18;

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<P> adj[100];

    int u, v;
    long long w;
    for(int i=0; i<m; ++i){
        scanf("%d %d %lld", &u, &v, &w);
        adj[u-1].push_back(P(w, v-1));
    }

    long long dist[100];
    int pre[100];
    bool isInsideCycle[100];
    bool plusCycle = false;

    fill(dist, dist+n, -INF);
    fill(pre, pre+n, -1);
    fill(isInsideCycle, isInsideCycle+n, false);
    dist[0] = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            for(auto &p: adj[j]){
                long long d = p.first;
                int next = p.second;
                if(dist[j] > -INF && dist[next] < dist[j] + d){ // 최대 경로라는 거 못 봄..
                    dist[next] = dist[j] + d;
                    pre[next] = j;
                    if(i == n-1){
                        isInsideCycle[j] = isInsideCycle[next] = true;
                    }
                }
            }
        }
    }
    // 최장경로가 여러 개 존재할 수 있으므로, pre[]에 담긴 하나의 경로만으로는 판단이 불가능.
    // 따라서 cycle을 구성하는 각각의 정점에 대하여 bfs로 도달 가능 여부 검사를 해야함.

    for(int i=0; i<n; ++i){
        // 시점에서 도달 가능한 cycle 구성 정점에 대하여 종점 도달 가능 여부 확인
        if(isInsideCycle[i]){
            bool endFlag = false;
            queue<int> q;
            bool visited[n];

            fill(visited, visited+n, false);

            visited[i] = true;
            q.push(i);

            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(auto& p: adj[curr]){
                    int next = p.second;
                    if(!visited[next]){
                        q.push(next);
                        visited[next] = true;
                        if(next == n-1){ endFlag = true; }
                    }
                }
            }
            // 사이클 -> 종점 가능하면 true
            if(endFlag){ plusCycle = true; break; }
        }
    }

    vector<int> path;
    if(plusCycle){ printf("-1\n"); }
    else{
        int i = n-1;
        while(true){
            path.push_back(i+1);
            if(pre[i] == -1){
                if(i == 0){
                    for(vector<int>::reverse_iterator it = path.rbegin(); it != path.rend(); ++it)
                        printf("%d ", *it);
                }
                else{ printf("-1\n"); }
                break;
            }
            i = pre[i];
        }
    }
    return 0;
}
/*
    벨만 포드는 다익스트라마냥 방문했다고 건너뛰는 게 아니기 때문에
    최대 경로를 구할 때도 사용할 수 있다.

    if문 조건에 -INF가 아니라 INF를 쓴 점, pre[0] != -1인 경우까지 고려하지 않은 점으로 인해
    92퍼에서 3번 틀렸다.

    pre[0] != -1인 경우는 뭘까?
    이미 출발할 때 시점을 방문했는데, 최장 경로에 시점이 끝인 간선이 포함되어 있다는 것.
    다시 말해 시점을 '중복 방문'한다는 것이다.

    + 근데 왜 line 39의 if 조건에서 -INF가 아니라 INF를 써도 돌아가는거지?
*/