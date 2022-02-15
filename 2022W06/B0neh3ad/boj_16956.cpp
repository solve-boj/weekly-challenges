#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};

    int r, c;
    cin >> r >> c;

    char land[r][c];
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cin >> land[i][j];
        }
    }

    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(land[i][j] == 'W'){
                for(int k=0; k<4; ++k){
                    int ny = i+dy[k];
                    int nx = j+dx[k];
                    if(ny >= 0 && ny < r && nx >= 0 && nx < c){
                        if(land[ny][nx] == 'S'){
                            cout << 0;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "1\n";
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cout << ((land[i][j] == '.') ? 'D' : land[i][j]);
        }
        cout << "\n";
    }

    return 0;
}