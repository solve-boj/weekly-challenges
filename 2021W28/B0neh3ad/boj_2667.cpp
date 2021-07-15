/*
    단지번호붙이기
    https://www.acmicpc.net/problem/2667
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int town[25][25];
int visited[25][25];

int dfs(int y, int x){
    int nodes = 1;
    if(visited[y][x] || !town[y][x]) { return 0; }
    visited[y][x] = true;

    if(x > 0) { nodes += dfs(y, x-1); }
    if(x < n-1) { nodes += dfs(y, x+1); }
    if(y > 0) { nodes += dfs(y-1, x); }
    if(y < n-1) { nodes += dfs(y+1, x); }

    return nodes;
}

void solution(){
    vector<int> nodes;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && town[i][j]){
                nodes.push_back(dfs(i, j));
            }
        }
    }
    sort(nodes.begin(), nodes.end());
    cout << nodes.size() << endl;
    for(vector<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
        cout << *it << endl;
    }
}

int main(void){
    cin >> n;

    char temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> temp;
            town[i][j] = temp - 48;
        }
    }

    solution();

    return 0;
}