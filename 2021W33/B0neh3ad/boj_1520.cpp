/*
    내리막 길
    https://www.acmicpc.net/problem/1520
*/
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int M, N;
int map[500][500];
vector<pii> index_map;
int dp[500][500];
int diry[] = {0, -1, 0, 1}, dirx[] = {1, 0, -1, 0};

// pair<map[y][x], y*N+x>

void bfs(){
    for(auto& p: index_map){
        int curr_y = p.second / N;
        int curr_x = p.second % N;
        for(int i=0; i<4; ++i){
            int prev_y = curr_y + diry[i];
            int prev_x = curr_x + dirx[i];
            if(prev_y >= 0 && prev_y < M && prev_x >= 0 && prev_x < N){
                if(map[curr_y][curr_x] < map[prev_y][prev_x]){
                    dp[prev_y][prev_x] += dp[curr_y][curr_x];
                }
            }
        }
    }
}

int main(void){
    scanf("%d %d", &M, &N);


    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &map[i][j]);
            index_map.push_back(pii(map[i][j], i*N+j));
        }
    }
    sort(index_map.begin(), index_map.end());
    dp[M-1][N-1] = 1;
    bfs();
    printf("%d", dp[0][0]);
    return 0;
}
/*
    내림차순 정렬..ㄷㄷ
    어케 생각하냐 이걸...
*/