/*
    빛의 경로 사이클
    https://programmers.co.kr/learn/courses/30/lessons/86052
*/

#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int direction[4][2] = {
    {1, 0}, //{x, y}
    {0, 1},
    {-1, 0},
    {0, -1}
};

struct StepInfo{
    int x;
    int y;
};
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int row_size = grid.size();
    int col_size = grid[0].size();
    bool visited[501][501][3][3] = {0};
    for(int i=0; i<row_size; i++){
        for(int k=0; k<col_size; k++){
            for(auto dir: direction){
                int dx = dir[0];
                int dy = dir[1];
                int length = 0;
                int startdx = dx;
                int startdy = dy;
                vector<pair<int, int>> next;
                next.push_back({k,i});
                while(next.size()>0){
                    pair<int,int> step_info = next.back();
                    next.pop_back();
                    if(length>0 && step_info.first == k && step_info.second == i && dx == startdx && dy == startdy){
                        break;
                    }
                    if(visited[step_info.second][step_info.first][dy+1][dx+1]){
                        length = 0;
                        break;
                    }
                    
                    visited[step_info.second][step_info.first][dy+1][dx+1] = true;
                    char type = grid[step_info.second][step_info.first];
                    int temp;
                    switch(type){
                        case 'S':
                            break;
                        case 'L':
                            temp = dy;
                            dy = -dx;
                            dx = temp;
                            break;
                        case 'R':
                            temp = dy;
                            dy = dx;
                            dx = -temp;
                            break;
                    }

                    next.push_back({(step_info.first + dx + col_size)%col_size, (step_info.second + dy + row_size)%row_size});
                    length++;
                }
                if(length != 0){
                    answer.push_back(length);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}