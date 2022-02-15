#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int l, board[300][300];
bool visited[300][300];
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};

pii init, goal;

int bfs(pii start){
    if(init == goal){ return 0; }
    for(int i=0; i<l; ++i){ fill(visited[i], visited[i]+l, false); }
    queue<pii> q;
    visited[start.first][start.second] = true;
    q.push(start);

    int step = 0;
    while(!q.empty()){
        ++step;
        int qsize = q.size();
        for(int i=0; i<qsize; ++i){
            pii curr = q.front();
            q.pop();

            for(int k=0; k<8; ++k){
                pii next = pii(curr.first + dy[k], curr.second + dx[k]);
                if(next.first >= 0 && next.first < l && next.second >= 0 && next.second < l){
                    if(!visited[next.first][next.second]){
                        if(next == goal){ return step; }
                        visited[next.first][next.second] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        cin >> l;
        cin >> init.first >> init.second;
        cin >> goal.first >> goal.second;
        cout << bfs(init) << "\n";
    }
    return 0;
}