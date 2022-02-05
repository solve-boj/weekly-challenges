#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 6561

char ans[MAX_SIZE][MAX_SIZE];

void sol(int y, int x, int size){
    if(size == 1){
        ans[y][x] = '*';
        return;
    }

    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(i != 1 || j != 1){
                sol(y+i*(size/3), x+j*(size/3), size/3);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        fill(ans[i], ans[i]+n, ' ');
    }
    sol(0, 0, n);

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}