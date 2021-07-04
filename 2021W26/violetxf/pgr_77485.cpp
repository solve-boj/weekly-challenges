/*
	행렬 테두리 회전하기
	https://programmers.co.kr/learn/courses/30/lessons/77485
*/
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> table(rows, vector<int>(columns));
    int num = 1;
    for(int i=0;i<rows;i++){
        for(int k=0;k<columns;k++){
            table[i][k] = num++;
        }
    }
    auto step = [&](int x1, int y1, int x2, int y2){
        int directions[4][2] = {
            {0, 1}, //x,y
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        int result = table[x1][y1];
        int hold = table[x1][y1];
        int x = x1;
        int y = y1;
        for(int* dir: directions){
            int cnt;
            if(dir[0]){
                cnt = x2-x1;
            } else {
                cnt = y2-y1;
            }
            while(cnt--){
                x+=dir[0];
                y+=dir[1];
                result = min(result, table[x][y]);
                int temp = table[x][y];
                table[x][y] = hold;
                hold = temp;
            }
        }
        answer.push_back(result);
    };
    for(vector<int> k: queries){
        step(k[0]-1, k[1]-1, k[2]-1, k[3]-1);
    }
    return answer;
}