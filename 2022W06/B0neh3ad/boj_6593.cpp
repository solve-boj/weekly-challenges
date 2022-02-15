#include <bits/stdc++.h>
using namespace std;

int l, r, c;
char building[30][30][30];
int dz[] = {0, 0, 0, 0, -1, 1}, dy[] = {0, -1, 0, 1, 0, 0}, dx[] = {1, 0, -1, 0, 0, 0};
int start;

int sol(){
    queue<int> q;
    q.push(start);

    int step = 1;
    while(!q.empty()){
        int qsize = q.size();
        for(int i=0; i<qsize; ++i){
            int cz = q.front() / (30*30);
            int cy = q.front() % (30*30) / 30;
            int cx = q.front() % 30;
            q.pop();

            for(int k=0; k<6; ++k){
                int nz = cz + dz[k];
                int ny = cy + dy[k];
                int nx = cx + dx[k];
                if(nz >= 0 && nz < l && ny >= 0 && ny < r && nx >= 0 && nx < c){
                    if(building[nz][ny][nx] == 'E'){
                        return step;
                    }
                    if(building[nz][ny][nx] == '.'){
                        building[nz][ny][nx] = '#';
                        q.push(nz*30*30 + ny*30 + nx);
                    }
                }
            }
        }
        ++step;
    }

    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    // cin.tie(NULL);
    while(true){
        cin >> l >> r >> c;
        if(l+r+c == 0){ break; }
        for(int i=0; i<l; ++i){
            for(int j=0; j<r; ++j){
                for(int k=0; k<c; ++k){
                    cin >> building[i][j][k];
                    if(building[i][j][k] == 'S'){
                        start = i*30*30 + j*30 + k;
                    }
                }
            }
        }

        int ans = sol();
        if(ans == -1){
            cout << "Trapped!\n";
        }
        else {
            cout << "Escaped in "<<ans<<" minute(s).\n";
        }

    }

    return 0;
}