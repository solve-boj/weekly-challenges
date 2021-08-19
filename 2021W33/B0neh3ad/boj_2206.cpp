/*
    벽 부수고 이동하기
    https://www.acmicpc.net/problem/2206
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> P;
// <<거리, 부순 블럭 개수>, <y, x>>

const int INF = 10000000;
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    int map[N][M];
    char temp;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf(" %c", &temp);
            map[i][j] = int(temp - 48);
        }
    }

    int dist[N][M][2];
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            dist[i][j][0] = INF; // crashed = 0일 때 최단 경로
            dist[i][j][1] = INF; // crashed = 1일 때 최단 경로
        }
    }
    priority_queue<P, vector<P>, greater<P> > pq;

    dist[0][0][0] = dist[0][0][1] = 1;
    pq.push(P({1, 0}, {0, 0}));
    
    while(!pq.empty()){
        int cost = pq.top().first.first;
        int crashed = pq.top().first.second;
        int curr_y = pq.top().second.first;
        int curr_x = pq.top().second.second;
        pq.pop();
        if(cost > dist[curr_y][curr_x][crashed]) continue;

        for(int i=0; i<4; ++i){
            int next_y = curr_y + dy[i];
            int next_x = curr_x + dx[i];

            if(next_y >= 0 && next_y < N && next_x >= 0 && next_x < M){ // 경계 체크
                if(crashed + map[next_y][next_x] <= 1){ // 갈 수 있는 곳
                    if(dist[next_y][next_x][ crashed + map[next_y][next_x] ] > dist[curr_y][curr_x][crashed] + 1){ // 최단 경로 갱신되는 경우라면
                        dist[next_y][next_x][ crashed + map[next_y][next_x] ] = dist[curr_y][curr_x][crashed] + 1;
                        pq.push(P({dist[next_y][next_x][ crashed + map[next_y][next_x] ], crashed + map[next_y][next_x]}, {next_y, next_x}));
                    }
                }
            }
        }
    }

    int answer = min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
    printf("%d", (answer >= INF) ? -1 : answer);

    return 0;
}
/*
    1, 2트: 벽 부술 때 ++crashed한 점에서 문제 생겼다고 판단. 그러나 그뿐만이 아니었음.
    3트: 벽을 부쉈을 때/부수지 않았을 때 최단경로를 아예 따로 구하면서 가야함.
    최단 경로가 아닌 경로로 중간 지점에 도달했으나 벽을 부수지 않은 경우
    VS
    최단 경로로 중간 지점에 도달했으나 벽을 부순 경우

    둘 중 후자가 정답 경로에 포함되는 경우가 존재하기 때문.

    그리고 애초에 이거는 가중치가 없으니 그냥 bfs로 풀어도 되는 문제..
*/