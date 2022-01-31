#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> blanks;
int sudoku[9][9];
bool flag = false;

void check(){
    // check whether this is correct sudoku
    // if correct, print it
    for(int i=0; i<9; ++i){
        int check[10] = {0, };
        for(int j=0; j<9; ++j){
            if(check[sudoku[i][j]]){
                return;
            }
            check[sudoku[i][j]] = 1;
        }
    }

    for(int i=0; i<9; ++i){
        int check[10] = {0, };
        for(int j=0; j<9; ++j){
            if(check[sudoku[j][i]]){
                return;
            }
            check[sudoku[j][i]] = 1;
        }
    }

    for(int l=0; l<9; ++l){
        int check[10] = {0, };
        for(int i=l/3*3; i<l/3*3 + 3; ++i){
            for(int j=l%3*3; j<l%3*3 + 3; ++j){
                if(check[sudoku[i][j]]){
                    return;
                }
                check[sudoku[i][j]] = 1;
            }
        }
    }

    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
    flag = true;
}

void sol(int cnt, int size){
    if(flag){
        return;
    }
    if(cnt == size){
        check();
        return;
    }

    int y = blanks[cnt].first;
    int x = blanks[cnt].second;
    int cand[10] = {0, };

    for(int i=0; i<9; ++i){
        cand[sudoku[y][i]] = 1;
    }
    for(int i=0; i<9; ++i){
        cand[sudoku[i][x]] = 1;
    }
    for(int i=y/3*3; i<y/3*3 + 3; ++i){
        for(int j=x/3*3; j<x/3*3 + 3; ++j){
            cand[sudoku[i][j]] = 1;
        }
    }

    for(int i=1; i<10; ++i){
        if(!cand[i]){
            sudoku[y][x] = i;
            sol(cnt+1, size);
        }
    }

    // backtracking
    sudoku[y][x] = 0;
}

int main(void){
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0){
                blanks.push_back({i, j});
            }
        }
    }

    sol(0, blanks.size());
    return 0;
}