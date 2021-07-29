/*
    토마토
    https://www.acmicpc.net/problem/7576
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N;
int flag = 0, not_cnt = 0;
int box[1000][1000];
queue<int> q;
int xdir[4] = {1, 0, -1, 0}, ydir[4] = {0, 1, 0, -1};

bool boundary_check(int y, int x){ return (((N-1-y)*y >= 0) && ((M-1-x)*x >= 0)); }

// 답을 return
int bfs(void){
    int cnt = 0, days = 0;
    while(!q.empty()){
        int qsize = q.size();
        for(int i=0; i<qsize; ++i){
            int curr_y = q.front() / M;
            int curr_x = q.front() % M;
            q.pop();
            for(int j=0; j<4; ++j){
                if(boundary_check(curr_y+ydir[j], curr_x+xdir[j])){
                    if(box[curr_y+ydir[j]][curr_x+xdir[j]] == 0){ // 주위에 안 익은 게 있다면
                        ++cnt; // 개수 세고
                        box[curr_y+ydir[j]][curr_x+xdir[j]] = 1; // 익히기
                        q.push((curr_y+ydir[j])*M+(curr_x+xdir[j]));
                    }
                }
            }
        }
        ++days; // 하루 지남 표시
        if(not_cnt == cnt){ break; }
    }
    if(not_cnt != cnt){ days = -1; }
    return days;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin >> box[i][j];
            if(box[i][j] == 1){ q.push(i*M+j); }
            if(box[i][j] == 0){
                flag = 1;
                ++not_cnt;
            }
        }
    }

    cout << (!flag ? 0 : bfs());
    return 0;
}