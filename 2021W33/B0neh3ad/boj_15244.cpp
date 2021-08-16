/*
    Bumped!
    https://www.acmicpc.net/problem/15422
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<pair<long long, int>, int> P; // <<거리, 비행기 탑승 횟수>, 위치>
const long long INF = 3000000000;
const int MAX_N = 50001;

int main(void){
    int n, m, f, s, t;
    scanf("%d %d %d %d %d", &n, &m, &f, &s, &t);
    
    vector<pair<long long, int> > adj[MAX_N];
    int u, v;
    long long w;
    for(int i=0; i<m; ++i){
        scanf("%d %d %lld", &u, &v, &w);
        // 양방향
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    // 비행기는 단 1번 가능
    for(int i=0; i<f; ++i){
        scanf("%d %d", &u, &v);
        // 단방향
        adj[u].push_back({0, v});
    }

    long long costs[MAX_N][2]; // [도착지][비행기 탑승 횟수]
    for(int i=0; i<MAX_N; ++i){ costs[i][0] = costs[i][1] = INF; }
    priority_queue<P, vector<P>, greater<P> > pq;

    costs[s][0] = 0;
    pq.push(P({0, 0}, s));
    while(!pq.empty()){
        long long cost = pq.top().first.first;
        int count = pq.top().first.second;
        int curr = pq.top().second;
        pq.pop();
        if(cost > costs[curr][count]) continue;

        for(auto& p: adj[curr]){
            long long next_cost = p.first;
            int next = p.second;
            if(count + !next_cost <= 1){ // 갈 수 있다면
                if(costs[next][count + !next_cost] > costs[curr][count] + next_cost){ // 비용이 갱신된다면
                    costs[next][count + !next_cost] = costs[curr][count] + next_cost;
                    pq.push(P({costs[next][count + !next_cost], count + !next_cost}, next));
                }
            }
        }
    }

    long long answer = min(costs[t][0], costs[t][1]);
    printf("%lld", answer);

    return 0;
}
/*
    1트: 11%에서 틀림
    -> long long으로 자료형 바꿈
    2트: 34%
    -> 아 ㅋㅋ 마지막에 %lld로 안 바꿨네..
    3트: 성공!
*/