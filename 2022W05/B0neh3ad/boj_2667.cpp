#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};
int n, nmap[25][25];
bool visited[25][25];
vector<int> cnt;

void bfs(pii start){
    queue<pii> q;

    visited[start.first][start.second] = true;
    q.push(start);

    while(!q.empty()){
        pii curr = q.front();
        q.pop();

        for(int i=0; i<4; ++i){
            pii next = pii(curr.first + dy[i], curr.second + dx[i]);
            if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < n){
                if(nmap[next.first][next.second] && !visited[next.first][next.second]){
                    visited[next.first][next.second] = true;
                    ++cnt.back();
                    q.push(next);
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            char c;
            cin >> c;
            nmap[i][j] = c - '0';
        }
    }

    for(int i=0; i<n; ++i){
        fill(visited[i], visited[i]+n, false);
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(nmap[i][j] && !visited[i][j]){
                cnt.push_back(1);
                bfs(pii(i, j));
            }
        }
    }

    sort(cnt.begin(), cnt.end());

    cout << cnt.size() << "\n";
    for(int elem: cnt){
        cout << elem << "\n";
    }

    return 0;
}