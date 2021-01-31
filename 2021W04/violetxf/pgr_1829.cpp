/*
    카카오프렌즈 컬러링북
    https://programmers.co.kr/learn/courses/30/lessons/1829
*/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dir[4][2]={ //{y,x}
        {-1,0},
        {0,-1},
        {0,1},
        {1,0}
    };
    vector<vector<bool>>checked(m, vector<bool>(n, false));
    for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
            if(picture[y][x]==0)continue;
            if(checked[y][x])continue;
            checked[y][x] = true;
            int color = picture[y][x];
            int size = 1;
            number_of_area++;
            queue<pair<int,int>> q;
            q.push(make_pair(y, x));
            while(!q.empty()){
                int y2 = q.front().first;
                int x2 = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int new_y = y2+dir[i][0];
                    int new_x = x2+dir[i][1];
                    if(new_y>=0 && new_x>=0 && new_y<m && new_x<n && picture[new_y][new_x] == color && !checked[new_y][new_x]){
                        checked[new_y][new_x] = true;
                        q.push(make_pair(new_y, new_x));
                        size++;
                    }
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, size);
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}