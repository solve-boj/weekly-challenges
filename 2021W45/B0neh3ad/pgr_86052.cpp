/*
    빛의 경로 사이클
    https://programmers.co.kr/learn/courses/30/lessons/86052?language=cpp
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int r = grid.size(), c = grid[0].size();
    int map[r][c][4]; // right, up, left, down
    int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};

    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            for(int k=0; k<4; ++k){
                map[i][j][k] = 0;
            }
        }
    }

    int cycle_idx = 0, cycle_size;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            for(int k=0; k<4; ++k){
                if(!map[i][j][k]){ // if not visit this direction
                    // set position of start, next point
                    int sy = i, sx = j;
                    int ny = sy, nx = sx;
                    int dir = k;

                    // set variables about cycle
                    ++cycle_idx;
                    cycle_size = 0;

                    // until come back
                    while(!map[ny][nx][dir]){
                        // mark and add to cycle
                        map[ny][nx][dir] = 1;
                        ++cycle_size;

                        // set next point
                        ny = (ny + dy[dir] + r) % r;
                        nx = (nx + dx[dir] + c) % c;

                        // set direction
                        switch(grid[ny][nx]){
                            case 'L': // turn left
                                dir = (dir+3) % 4;
                                break;

                            case 'R': // turn right
                                dir = (dir+1) % 4;
                                break;
                        }
                    }
                    // add the length of cycle
                    answer.emplace_back(cycle_size);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

/*
    쌩-구현 문제.
    아래와 같은 issue가 있었다.
    1) index 처리를 위한 modulo 연산
    2) next point를 언제 계산? edge는 언제 cycle에 count?

    + 배열의 초기화, 오름차순! 정렬

    시간복잡도는 O(n). (각 edge는 최대 2번 방문하는 것이 보장되므로.)
*/