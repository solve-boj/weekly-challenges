#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];

void merge(int dir) {
    // cout << "merge("<<dir<<")\n";
    switch(dir){
        case 0: // right
        for(int i=0; i<n; ++i){
            for(int j=n-2; j>=0; --j){
                if(board[i][j] == board[i][j+1]){
                    board[i][j+1] += board[i][j];
                    board[i][j] = 0;
                }
            }
        }
        break;

        case 1: // up
        for(int j=0; j<n; ++j){
            for(int i=1; i<n; ++i){
                if(board[i][j] == board[i-1][j]){
                    board[i-1][j] += board[i][j];
                    board[i][j] = 0;
                }
            }
        }
        break;
        
        case 2: // left
        for(int i=0; i<n; ++i){
            for(int j=1; j<n; ++j){
                if(board[i][j] == board[i][j-1]){
                    board[i][j-1] += board[i][j];
                    board[i][j] = 0;
                }
            }
        }
        break;

        case 3: // down
        for(int j=0; j<n; ++j){
            for(int i=n-2; i>=0; --i){
                if(board[i][j] == board[i+1][j]){
                    board[i+1][j] += board[i][j];
                    board[i][j] = 0;
                }
            }
        }
        break;
    }
}

void push(int dir) {
    // cout << "push("<<dir<<")\n";
    switch(dir){
        case 0: // right
        for(int i=0; i<n; ++i){
            for(int j=n-2; j>=0; --j){
                if(board[i][j]){
                    int loc = j;
                    while(!board[i][loc+1]){
                        board[i][loc+1] = board[i][loc];
                        board[i][loc] = 0;
                        if(++loc >= n-1){ break; }
                    }
                }
            }
        }
        break;

        case 1: // up
        for(int j=0; j<n; ++j){
            for(int i=1; i<n; ++i){
                if(board[i][j]){
                    int loc = i;
                    while(!board[loc-1][j]){
                        board[loc-1][j] = board[loc][j];
                        board[loc][j] = 0;
                        if(--loc <= 0){ break; }
                    }
                }
            }
        }
        break;
        
        case 2: // left
        for(int i=0; i<n; ++i){
            for(int j=1; j<n; ++j){
                if(board[i][j]){
                    int loc = j;
                    while(!board[i][loc-1]){
                        board[i][loc-1] = board[i][loc];
                        board[i][loc] = 0;
                        if(--loc <= 0){ break; }
                    }
                }
            }
        }
        break;

        case 3: // down
        for(int j=0; j<n; ++j){
            for(int i=n-2; i>=0; --i){
                if(board[i][j]){
                    int loc = i;
                    while(!board[loc+1][j]){
                        board[loc+1][j] = board[loc][j];
                        board[loc][j] = 0;
                        if(++loc >= n-1){ break; }
                    }
                }
            }
        }
        break;
    }
}

int sol(int step){
    // save prev status
    int ans = 0;
    int prev[20][20];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            ans = max(ans, board[i][j]);
            prev[i][j] = board[i][j];
        }
    }
    if(step >= 5){ return ans; }

    for(int i=0; i<4; ++i){
        // move board
        push(i);
        merge(i);
        push(i);

        int temp = sol(step+1);
        ans = max(ans, temp);

        // revert board
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                board[i][j] = prev[i][j];
            }
        }
    }
    return ans;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> board[i][j];
        }
    }

    cout << sol(0);
    return 0;
}