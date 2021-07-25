/*
    미로 탐색
    https://www.acmicpc.net/problem/2178
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int ground[101][101];
int visited[101*101];

int bfs(int y, int x){
    queue<int> q;
    
    visited[y*m+x] = 1;
    q.push(y*m+x);

    int curr_y, curr_x;
    int level = 1;
    while(!q.empty()){
        int qsize = q.size();
        // cout << "-- level " << level << " --" << '\n';
        for(int i=0; i<qsize; ++i){
            curr_y = q.front() / m;
            curr_x = q.front() % m;
            if(!curr_x){ curr_y--; curr_x = m; }
            // cout << curr_y << " " << curr_x << '\n';
            if(curr_y == n && curr_x == m){ return level; }
            q.pop();
            if(curr_y > 1 && ground[curr_y-1][curr_x] && !visited[(curr_y-1)*m+curr_x]){
                visited[(curr_y-1)*m+curr_x] = 1;
                q.push((curr_y-1)*m+curr_x);
            }
            if(curr_y < n && ground[curr_y+1][curr_x] && !visited[(curr_y+1)*m+curr_x]){
                visited[(curr_y+1)*m+curr_x] = 1;
                q.push((curr_y+1)*m+curr_x);
            }
            if(curr_x > 1 && ground[curr_y][curr_x-1] && !visited[curr_y*m+curr_x-1]){
                visited[curr_y*m+curr_x-1] = 1;
                q.push(curr_y*m+curr_x-1);
            }
            if(curr_x < m && ground[curr_y][curr_x+1] && !visited[curr_y*m+curr_x+1]){
                visited[curr_y*m+curr_x+1] = 1;
                q.push(curr_y*m+curr_x+1);
            }
        }
        level++;
    }

    level--;
    return level;
}

int main(void){
    cin >> n >> m;

    char temp;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> temp;
            ground[i][j] = int(temp - 48);
        }
    }

    cout << bfs(1, 1);

    return 0;
}
/*
    visited 선언 후에
    fill, memset, 반복문 등으로 0으로 초기화를 따로 해주거나,
    아님 전역변수로 선언하거나...
*/