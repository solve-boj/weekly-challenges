/*
    별 찍기 - 11
    https://www.acmicpc.net/problem/2448
*/
#include <iostream>

using namespace std;

char stars[3072][6144];

void drawStar(int y, int x, int num){
    if(num == 3){ // base case
        stars[y][x] = '*';
        stars[y+1][x-1] = stars[y+1][x+1] = '*';
        for(int i=x-2; i<=x+2; ++i){ stars[y+2][i] = '*'; }
    }
    else{
        drawStar(y, x, num/2);
        drawStar(y+num/2, x-num/2, num/2);
        drawStar(y+num/2, x+num/2, num/2);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        for(int j=0; j<2*n-1; ++j){
            stars[i][j] = ' ';
        }
    }

    drawStar(0, n-1, n);

    for(int i=0; i<n; ++i){
        for(int j=0; j<2*n-1; ++j){
            cout << stars[i][j];
        }
        cout << "\n";
    }

    return 0;
}