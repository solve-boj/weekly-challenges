/*
    나이트의 이동
    https://www.acmicpc.net/problem/7562
*/
#include <iostream>
#include <queue>
using namespace std;
int dir[8][2] = {
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1,2},
    {1, -2},
    {2, -1},
    {2, 1},
    {1, 2}
};
int main(){
    int T;
    
    cin>>T;
    while(T--){
        int l;
        cin>>l;
        int cur_y, cur_x;
        cin>>cur_y>>cur_x;
        int obj_y, obj_x;
        cin>>obj_y>>obj_x;
        if(cur_y==obj_y&&cur_x==obj_x){
            cout<<"0\n";
            continue;
        }
        int visited[301][301]={0};
        visited[cur_y][cur_x]=1;
        bool arrived = false;
        int result = 0;
        queue<pair<pair<int,int>, int>> q;
        q.push(make_pair(make_pair(cur_y, cur_x), 0));
        while(!q.empty()){
            int y = q.front().first.first;
            int x = q.front().first.second;
            int steps = q.front().second+1;
            q.pop();
            
            for(int i=0;i<8;i++){
                int y2 = y+dir[i][0];
                int x2 = x+dir[i][1];
                if(y2>=0&&y2<l&&x2>=0&&x2<l){
                    if(visited[y2][x2])continue;
                    
                    if(y2==obj_y && x2==obj_x){
                        arrived = true;
                        result = steps;
                        break;
                    }
                    visited[y2][x2] = 1;
                    q.push(make_pair(make_pair(y2, x2), steps));
                    
                }
            }
            if(arrived)break;
        }
        cout<<result<<"\n";
    }
    
    
}