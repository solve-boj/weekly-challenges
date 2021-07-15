/*
    영역 구하기
    https://www.acmicpc.net/problem/2583
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int area[100][100];
int visited[100][100];

int dfs(int y, int x){
    int nodes = 1;
    if(visited[y][x] || area[y][x]) { return 0; }
    visited[y][x] = 1;

    if(x > 0) { nodes += dfs(y, x-1); }
    if(x < n-1) { nodes += dfs(y, x+1); }
    if(y > 0) { nodes += dfs(y-1, x); }
    if(y < m-1) { nodes += dfs(y+1, x); }
    // cout << "visited (" << y << ", " << x << ")" << endl;

    return nodes;
}

void solution(){
    vector<int> nodes;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && !area[i][j]){
                nodes.push_back(dfs(i, j));
                // cout << "area " << nodes.size()-1 << " is " << nodes.back() << endl;
            }
        }
    }
    sort(nodes.begin(), nodes.end());
    cout << nodes.size() << endl;
    for(vector<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
        cout << *it << " ";
    }
}

int main(void){
    int k;
    cin >> m >> n >> k;

    for(int i=0; i<k; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=y1; j<y2; j++){
            for(int k=x1; k<x2; k++){
                area[j][k] = 1;
            }
        }
    }

    solution();
    return 0;
}