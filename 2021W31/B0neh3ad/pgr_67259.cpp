/*
    [카카오 인턴] 경주로 건설
    https://programmers.co.kr/learn/courses/30/lessons/67259
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dir_x[4] = {1, 0, -1, 0}, dir_y[4] = {0, -1, 0, 1};
int cost[25][25][4];

int solution(vector<vector<int>> board) {
    int bsize = board.size();
    queue<pair<int, int> > q;

    q.push({0, 0});
    
    while(!q.empty()){
        // int qsize = q.size();
        // for(int h=0; h=qsize; ++h){
        int curr_y = q.front().first;
        int curr_x = q.front().second;
        q.pop();
        
        for(int i=0; i<4; ++i){
            int next_y = curr_y + dir_y[i];
            int next_x = curr_x + dir_x[i];
            if(0 <= next_x && next_x < bsize && 0 <= next_y && next_y < bsize){ // 범위 안에 있다면?
                if(!board[next_y][next_x]){ // 벽이 아니라면?
                    int temp = cost[next_y][next_x][i];
                    if(curr_y == 0 && curr_x == 0){ // 현재 출발점인 경우
                        cost[next_y][next_x][i] = 100;
                    }
                    else{ // 출발점이 아닌 경우
                        for(int j=0; j<4; ++j){ // 출발점에서 현재 지점으로 올 수 있는 방향 탐색
                            if(cost[curr_y][curr_x][j]){ // 올 수 있는 방향이라면 최단경로 저장
                                if(cost[next_y][next_x][i]){
                                    cost[next_y][next_x][i] = min(cost[next_y][next_x][i], cost[curr_y][curr_x][j] + ((i+j)%2 ? 600 : 100));
                                }
                                else{
                                    cost[next_y][next_x][i] = cost[curr_y][curr_x][j] + ((i+j)%2 ? 600 : 100);
                                }
                            }
                        }
                    }
                    // 최소 비용 갱신된 경우 큐에 저장
                    if(temp != cost[next_y][next_x][i]){ q.push({next_y, next_x}); }
                }
            }
        }
    }

    int answer = 0;
    for(int i=0; i<4; ++i){ // 최소 비용 저장
        if(cost[bsize-1][bsize-1][i]){
            answer = answer ? min(answer, cost[bsize-1][bsize-1][i]) : cost[bsize-1][bsize-1][i];
        }
    }

    return answer;
}