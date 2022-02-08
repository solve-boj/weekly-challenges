#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int sudoku[9][9];
vector<pii> blank;
bool is_solved;

void sol(int idx){
    if(is_solved){ return; }
    if(idx == blank.size()){
        is_solved = true;
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                cout << sudoku[i][j];
            }
            cout << "\n";
        }
        return;
    }
    
    int y = blank[idx].first;
    int x = blank[idx].second;

    bool exclude[10] = {0, };
    for(int i=0; i<9; ++i){
        exclude[sudoku[i][x]] = exclude[sudoku[y][i]] = true;
    }
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            exclude[sudoku[(y/3)*3 + i][(x/3)*3 + j]] = true;
        }
    }

    for(int i=1; i<=9; ++i){
        if(!exclude[i]){
            sudoku[y][x] = i;
            sol(idx+1);
        }
    }

    sudoku[y][x] = 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char inp;
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cin >> inp;
            sudoku[i][j] = inp - '0';
            if(!sudoku[i][j]){
                blank.push_back(pii(i, j));
            }
        }
    }

    sol(0);
    return 0;
}