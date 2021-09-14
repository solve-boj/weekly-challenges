/*
    게임 맵 최단거리
    https://programmers.co.kr/learn/courses/30/lessons/1844
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

bool isInside(int y, int ysize, int x, int xsize){ return y*(ysize-1-y) >= 0 && x*(xsize-1-x) >= 0; }

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};
    int h = maps.size(), w = maps[0].size();

    queue<pii> q;

    maps[0][0] = 2;
    q.push({0, 0});
    while(!q.empty()){
        int curr_y = q.front().first;
        int curr_x = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i){
            int next_y = curr_y + dy[i];
            int next_x = curr_x + dx[i];
            if(isInside(next_y, h, next_x, w)){
                if(maps[next_y][next_x] == 1){
                    maps[next_y][next_x] = maps[curr_y][curr_x] + 1;
                    q.push({next_y, next_x});
                }
            }
        }
    }

    answer = maps[h-1][w-1];
    if(answer <= 1){ answer = 0; }
    return --answer;
}