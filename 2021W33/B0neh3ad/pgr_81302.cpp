/*
    거리두기 확인하기
    https://programmers.co.kr/learn/courses/30/lessons/81302
*/
#include <string>
#include <vector>

using namespace std;

int diry[] = {0, -1, 0, 1}, dirx[] = {1, 0, -1, 0};
int diay[] = {-1, -1, 1, 1}, diax[] = {1, -1, -1, 1};

bool isInside(int y, int x){ return ((y*(4-y) >= 0) && (x*(4-x) >= 0)); }

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto& room: places){
        bool isOK = true;
        for(int i=0; i<5; ++i){
            for(int j=0; j<5; ++j){
                if(room[i][j] == 'P'){
                    // 거리 1
                    for(int k=0; k<4; ++k){
                        int next_y = i + diry[k];
                        int next_x = j + dirx[k];
                        if(isInside(next_y, next_x)){
                            if(room[next_y][next_x] == 'P'){
                                isOK = false;
                            }
                        }
                    }
                    // 거리 2 (직선)
                    for(int k=0; k<4; ++k){
                        int next_y = i + 2*diry[k];
                        int next_x = j + 2*dirx[k];
                        if(isInside(next_y, next_x)){
                            if(room[next_y][next_x] == 'P' && room[i + diry[k]][j + dirx[k]] == 'O'){
                                isOK = false;
                            }
                        }
                    }
                    // 거리 2 (대각)
                    for(int k=0; k<4; ++k){
                        int next_y = i + diay[k];
                        int next_x = j + diax[k];
                        if(isInside(next_y, next_x)){
                            if(room[next_y][next_x] == 'P' && (room[i + diry[k]][j + dirx[k]] == 'O' || room[i + diry[(k+1)%4]][j + dirx[(k+1)%4]] == 'O')){
                                isOK = false;
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(int(isOK));
    }
    return answer;
}
/*
    1명이 방 안에 들어오면 상하좌우로 인접해있는 칸에 누가 들어오면 안되고,
    해당 칸에 인접한 또 다른 사람이 있으면 안 된다.
*/