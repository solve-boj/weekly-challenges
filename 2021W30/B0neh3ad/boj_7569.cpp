/*
    토마토
    https://www.acmicpc.net/problem/7569
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, H;
int box[100][100][100];
int flag = 0, not_cnt = 0;
queue<int> q_z, q_y, q_x;
int z_dir[6] = {0, 0, 0, 0, 1, -1}, y_dir[6] = {0, 1, 0, -1, 0, 0}, x_dir[6] = {1, 0, -1, 0, 0, 0};

bool boundary_check(int z, int y, int x){ return (((H-1-z)*z >= 0) && ((N-1-y)*y >= 0) && ((M-1-x)*x >= 0)); }

// first는 방문한 0의 개수, second는 답 return
int bfs(){
    int cnt = 0, days = 0;
    while(!q_z.empty()){
        int qsize = q_z.size();
        for(int i=0; i<qsize; ++i){
            int curr_z = q_z.front(), curr_y = q_y.front(), curr_x = q_x.front();
            q_z.pop();
            q_y.pop();
            q_x.pop();

            for(int j=0; j<6; ++j){
                int next_z = curr_z+z_dir[j], next_y = curr_y+y_dir[j], next_x = curr_x+x_dir[j];
                if(boundary_check(next_z, next_y, next_x)){
                    if(box[next_z][next_y][next_x] == 0){
                        ++cnt;
                        box[next_z][next_y][next_x] = 1;
                        q_z.push(next_z);
                        q_y.push(next_y);
                        q_x.push(next_x);
                    }
                }
            }
        }
        ++days;
        if(not_cnt == cnt){ break; }
    }
    if(not_cnt != cnt){ days = -1; }
    return days;
}

int main(void){
    cin >> M >> N >> H;
    for(int i=0; i<H; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<M; ++k){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){ // 익은 거는 push
                    q_z.push(i);
                    q_y.push(j);
                    q_x.push(k);
                }
                if(box[i][j][k] == 0){ // 안 익은 건 flag 올리고 cnt
                    flag = 1;
                    ++not_cnt;
                }
            }
        }
    }

    cout << (!flag ? 0 : bfs());
    return 0;
}

/*
    구조체를 선언한다음
    queue<STRUCT> q;
    식으로 만들고 구조체를 push하는 방법도 있다
*/