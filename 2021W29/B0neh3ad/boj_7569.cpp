/*
    토마토
    https://www.acmicpc.net/problem/7569
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n, h;
int box[100][100][100];
queue<int> q;

int check(){
    for(int i=0; i<h; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<m; ++k){
                if(!box[i][j][k])
                    return 0;
            }
        }
    }
    return 1;
}

void printbox(){
    cout << '\n';
    for(int i=0; i<h; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<m; ++k){
                cout << box[i][j][k];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << "--------------" << '\n';
}

int bfs(){
    int level = 0;
    int curr_z, curr_y, curr_x;
    while(!q.empty()){
        int qsize = q.size();
        // cout << qsize << '\n';
        for(int i=0; i<qsize; ++i){
            curr_z = q.front() / 10000;
            curr_y = q.front() / 100;
            curr_x = q.front() % 100;
            q.pop();

            if(curr_z > 0 && !box[curr_z-1][curr_y][curr_x]){
                box[curr_z-1][curr_y][curr_x] = 1;
                q.push((curr_z-1)*10000+curr_y*100+curr_x);
            }
            if(curr_z < h-1 && !box[curr_z+1][curr_y][curr_x]){
                box[curr_z+1][curr_y][curr_x] = 1;
                q.push((curr_z+1)*10000+curr_y*100+curr_x);
            }
            if(curr_y > 0 && !box[curr_z][curr_y-1][curr_x]){
                box[curr_z][curr_y-1][curr_x] = 1;
                q.push(curr_z*10000+(curr_y-1)*100+curr_x);
            }
            if(curr_y < n-1 && !box[curr_z][curr_y+1][curr_x]){
                box[curr_z][curr_y+1][curr_x] = 1;
                q.push(curr_z*10000+(curr_y+1)*100+curr_x);
            }
            if(curr_x > 0 && !box[curr_z][curr_y][curr_x-1]){
                box[curr_z][curr_y][curr_x-1] = 1;
                q.push(curr_z*10000+curr_y*100+(curr_x-1));
            }
            if(curr_x < m-1 && !box[curr_z][curr_y][curr_x+1]){
                box[curr_z][curr_y][curr_x+1] = 1;
                q.push(curr_z*10000+curr_y*100+(curr_x+1));
            }
        }
        // printbox();
        ++level;
    }
    --level;
    return level;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;

    int cnt_not = 0;
    for(int i=0; i<h; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<m; ++k){
                cin >> box[i][j][k];
                if(!box[i][j][k])
                    ++cnt_not;
                if(box[i][j][k] == 1){
                    q.push(i*10000+j*100+k);
                    // cout << "now pushed: " << i << " " << j << " " << k << '\n';
                }
            }
        }
    }

    if(!cnt_not){
        cout << 0;
    }
    else{
        int result = bfs();
        cout << (check() ? result : -1);
    }

    return 0;
}