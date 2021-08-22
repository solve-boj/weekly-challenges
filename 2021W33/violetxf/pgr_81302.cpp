/*
    거리두기 확인하기
    https://programmers.co.kr/learn/courses/30/lessons/81302
*/
#include <string>
#include <vector>

using namespace std;
int straight[4][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};
int diagonal[4][2] = {
    {-1, -1},
    {1, 1},
    {-1, 1},
    {1, -1}
};
bool check(vector<string>& place, int firsty, int firstx, int y, int x, int depth){
    if(depth==2) return true;
    for(int i=0;i<4;i++){
        int dx = x+straight[i][0];
        int dy = y+straight[i][1];
        if(dx==firstx && dy==firsty)continue;
        if(dx<0 || dx>4 || dy<0 || dy>4)continue;
        if(place[dy][dx] == 'P'){
            return false;
        } else if(place[dy][dx] == 'O'){
            if(!check(place, firsty, firstx, dy, dx, depth+1)){
                return false;
            }
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto& place: places){
        bool result = true;
        for(int i=0;i<5;i++){
            for(int k=0;k<5;k++){
                char current = place[i][k];
                if(current == 'P'){
                    if(!check(place, i,k,i,k, 0)){
                        result = false;
                        break;
                    }
                }
            }
            if(!result)break;
        }
        if(result){
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }
    return answer;
}