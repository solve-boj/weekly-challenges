#include <iostream>

using namespace std;

int n, m;
int corridor[101][101];
int visited[101][101];

int dfs(int y, int x){
    int nodes = 1;

    if(visited[y][x] || !corridor[y][x]) { return 0; }
    // cout << "visited [" << y << ", " << x << "]" << endl;
    visited[y][x] = 1;

    if(x > 1) { nodes += dfs(y, x-1); }
    if(x < m) { nodes += dfs(y, x+1); }
    if(y > 1) { nodes += dfs(y-1, x); }
    if(y < n) { nodes += dfs(y+1, x); }

    return nodes;
}

int solution(){
    int max_nodes = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(corridor[i][j] && !visited[i][j]){
                max_nodes = max(max_nodes, dfs(i, j));
                // cout << "max_nodes: " << max_nodes << endl;
            }
        }
    }

    return max_nodes;
}

int main(void){
    int k;
    cin >> n >> m >> k;

    for(int i=0; i<k; i++){
        int r, c;
        cin >> r >> c;
        corridor[r][c] = 1;
    }

    cout << solution();
    return 0;
}