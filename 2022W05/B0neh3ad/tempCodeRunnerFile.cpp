#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];

int sol(int step, int dir){
    int prev[20][20];

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            prev[i][j] = board[i][j];
        }
    }

    switch(dir){
        case 0: // left
        for(int i=0; i<n; ++i){
            int idx = 0;
            for(int j=0; j<n; ++j){
                if(prev[i][j] != 0){
                    board[i][idx++] = prev[i][j];
                }
            }
            while(idx < n){
                board[i][idx++] = 0;
            }
        }
        break;

        case 1: // up
        for(int j=0; j<n; ++j){
            int idx = 0;
            for(int i=0; i<n; ++i){
                if(prev[i][j] != 0){
                    board[idx++][j] = prev[i][j];
                }
            }
            while(idx < n){
                board[idx++][j] = 0;
            }
        }
        break;

        case 2: // right
        for(int i=0; i<n; ++i){
            int idx = n-1;
            for(int j=n-1; j>=0; --j){
                if(prev[i][j] != 0){
                    board[i][idx--] = prev[i][j];
                }
            }
            while(idx >= 0){
                board[i][idx--] = 0;
            }
        }
        break;

        case 3: // down
        for(int j=0; j<n; ++j){
            int idx = n-1;
            for(int i=n-1; i>=0; --i){
                if(prev[i][j] != 0){
                    board[idx--][j] = prev[i][j];
                }
            }
            while(idx >= 0){
                board[idx--][j] = 0;
            }
        }
        break;
    }

    switch(dir){
        case 0:
        for(int i=0; i<n; ++i){
            for(int j=0; j<n-1; ++j){
                if(board[i][j] == board[i][j+1]){
                    board[i][j] *= 2;
                    for(int k=j+1; k<n-1; ++k){
                        board[i][k] = board[i][k+1];
                    }
                    board[i][n-1] = 0;
                }
            }
        }
        break;
        
        case 1:
        for(int j=0; j<n; ++j){
            for(int i=0; i<n-1; ++i){
                if(board[i][j] == board[i+1][j]){
                    board[i][j] *= 2;
                    for(int k=i+1; k<n-1; ++k){
                        board[k][j] = board[k+1][j];
                    }
                    board[n-1][j] = 0;
                }
            }
        }
        break;
        
        case 2:
        for(int i=0; i<n; ++i){
            for(int j=n-1; j>0; --j){
                if(board[i][j] == board[i][j-1]){
                    board[i][j] *= 2;
                    for(int k=j-1; k>0; --k){
                        board[i][k] = board[i][k-1];
                    }
                    board[i][0] = 0;
                }
            }
        }
        break;
        
        case 3:
        for(int j=0; j<n; ++j){
            for(int i=n-1; i>0; --i){
                if(board[i][j] == board[i-1][j]){
                    board[i][j] *= 2;
                    for(int k=i-1; k>0; --k){
                        board[k][j] = board[k-1][j];
                    }
                    board[0][j] = 0;
                }
            }
        }
        break;
    }

    int res = 0;
    if(step == 5){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                res = max(res, board[i][j]);
            }
        }
        // cout << "step: " << step << ", dir: " << dir << ", res: " << res << "\n";
        return res;
    }

    for(int i=0; i<4; ++i){
        res = max(res, sol(step+1, i));
    }

    // go back
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            board[i][j] = prev[i][j];
        }
    }

    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int res = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> board[i][j];
            res = max(res, board[i][j]);
        }
    }

    for(int i=0; i<4; ++i){
        res = max(res, sol(1, i));
    }

    cout << res;
    return 0;
}