/*
    유기농 배추
    https://www.acmicpc.net/problem/1012
*/
#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

int m, n;
int check[50][50];
bool visited[50][50];

void dfs(int y, int x){
    if(!check[y][x] || visited[y][x]) { return; }
    visited[y][x] = true;
    if(x > 0){ dfs(y, x-1); }
    if(x < (m - 1)){ dfs(y, x+1); }
    if(y > 0){ dfs(y-1, x); }
    if(y < (n - 1)){ dfs(y+1, x); }
}

int solution(){
    int components = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j] && !visited[i][j]){
                components++;
                dfs(i, j);
                // cout << "visited (" << j << ", " << i << ") (components: " << components << ")" << endl;
            }
        }
    }
    return components;
}

int main(void){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int k;
        cin >> m >> n >> k;
        
        memset(check, 0, sizeof(check));
        memset(visited, false, sizeof(visited));

        int x, y;
        for(int j=0; j<k; j++){
            cin >> x >> y;
            check[y][x] = 1;
        }

        cout << solution() << endl;
    }
    return 0;
}