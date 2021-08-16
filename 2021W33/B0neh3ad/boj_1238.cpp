/*
    파티
    https://www.acmicpc.net/problem/1238
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
const int MAX_V = 1001;
const int INF = 10000000;

int main(void){
    int N, M, X;
    scanf("%d %d %d", &N, &M, &X);
    --X;

    vector<P> adj[N];
    int u, v, ti;
    for(int i=0; i<M; ++i){
        scanf("%d %d %d", &u, &v, &ti);
        adj[u-1].push_back(P(ti, v-1));
    }

    int res[N] = {0};
    
    // O(MNlogN) <- 어떻게 개선?
    for(int idx=0; idx<N; ++idx){
        int time[MAX_V];
        fill(time, time+MAX_V, INF);
        priority_queue<P, vector<P>, greater<P> > pq;

        time[idx] = 0;
        pq.push(P(0, idx));

        while(!pq.empty()){
            int curr_t = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if(curr_t > time[curr]) continue;

            for(auto& p: adj[curr]){
                int next_t = p.first;
                int next = p.second;
                if(time[next] > time[curr] + next_t){
                    time[next] = time[curr] + next_t;
                    pq.push(P(time[next], next)); // 이거 빼먹었었음
                }
            }
        }

        if(idx != X)
            res[idx] += time[X]; // idx -> X (가는 시간)
        else
            for(int j=0; j<N; ++j)
                res[j] += time[j]; // X -> j (오는 시간)
    }

    int answer = 0;
    for(int i=0; i<N; ++i){
        answer = max(answer, res[i]);
    }

    printf("%d", answer);
    return 0;
}

/*
    어떻게 하면 "왕복" 시간을 빠르게 계산할 수 있는가?
    1) 일단 최대 힙으로 해서 시간 많이 낭비함...
    -> 고치니까 바로 맞음...
*/