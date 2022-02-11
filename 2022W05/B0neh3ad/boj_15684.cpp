#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int ladder[30][9];
int b[270][2], len=0;

bool check(){
    for(int i=0; i<n; ++i){
        int curr = i;
        for(int j=0; j<h; ++j){
            if(curr > 0){
                if(ladder[j][curr-1]){
                    --curr; continue;
                }
            }
            if(curr < n-1){
                if(ladder[j][curr]){
                    ++curr; continue;
                }
            }
        }
        if(curr != i){ return false; }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;

    for(int i=0; i<m; ++i){
        int x, y;
        cin >> y >> x;
        ladder[y-1][x-1] = 1;
    }

    for(int i=0; i<h; ++i){
        for(int j=0; j<n-1; ++j){
            if(!ladder[i][j]){
                b[len][0] = i;
                b[len][1] = j;
                ++len;
            }
        }
    }

    int ans = -1;
    if(check()){ ans = 0; }

    if(ans == -1){
        for(int i=0; i<len&&ans==-1; ++i){
            ladder[b[i][0]][b[i][1]] = 1;
            if(check()){ ans = 1; }
            ladder[b[i][0]][b[i][1]] = 0;
        }
    }

    if(ans == -1){
        for(int i=0; i<len&&ans==-1; ++i){
            ladder[b[i][0]][b[i][1]] = 1;

            for(int j=i+1; j<len&&ans==-1; ++j){
                ladder[b[j][0]][b[j][1]] = 1;
                if(check()){ ans = 2; }
                ladder[b[j][0]][b[j][1]] = 0;
            }

            ladder[b[i][0]][b[i][1]] = 0;
        }
    }

    if(ans == -1){
        for(int i=0; i<len&&ans==-1; ++i){
            ladder[b[i][0]][b[i][1]] = 1;

            for(int j=i+1; j<len&&ans==-1; ++j){
                ladder[b[j][0]][b[j][1]] = 1;

                for(int k=j+1; k<len&&ans==-1; ++k){
                    ladder[b[k][0]][b[k][1]] = 1;
                    if(check()){ ans = 3; }
                    ladder[b[k][0]][b[k][1]] = 0;
                }

                ladder[b[j][0]][b[j][1]] = 0;
            }

            ladder[b[i][0]][b[i][1]] = 0;
        }
    }

    cout << ans;

    return 0;
}