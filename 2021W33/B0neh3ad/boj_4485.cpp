/*
    녹색 옷 입은 애가 젤다지?
    https://www.acmicpc.net/problem/4485
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > P;
const int INF = 10000000;
const int MAX_N = 125;

int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

int main(void){
    int t = 1;
    while(true){
        int N;
        scanf("%d", &N);
        if(!N) break;
        
        int cave[N][N];
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                scanf("%d", &cave[i][j]);
            }
        }

        int cost[MAX_N][MAX_N];
        for(int i=0; i<MAX_N; ++i){ fill(cost[i], cost[i]+MAX_N, INF); }
        priority_queue<P, vector<P>, greater<P> > pq;

        cost[0][0] = cave[0][0];
        pq.push(P(cave[0][0], {0, 0}));

        while(!pq.empty()){
            int lost = pq.top().first;
            int curr_y = pq.top().second.first;
            int curr_x = pq.top().second.second;
            pq.pop();
            if(lost > cost[curr_y][curr_x]) continue;

            for(int i=0; i<4; ++i){
                int next_y = curr_y + dy[i];
                int next_x = curr_x + dx[i];
                if(next_y >= 0 && next_y < N && next_x >= 0 && next_x < N){ // 경계 내에 있다면
                    if(cost[next_y][next_x] > cost[curr_y][curr_x] + cave[next_y][next_x]){
                        cost[next_y][next_x] = cost[curr_y][curr_x] + cave[next_y][next_x];
                        pq.push(P(cost[next_y][next_x], {next_y, next_x}));
                    }
                }
            }
        }

        printf("Problem %d: %d\n", t++, cost[N-1][N-1]);
    }
    return 0;
}
/*
    1트: 시간초과...
    -> 일단 최대 힙이 문제인 거 같아 고침 -> 바로 맞음...
*/