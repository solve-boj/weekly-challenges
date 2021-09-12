/*
    [미포함]박스 그림 문자
    https://www.acmicpc.net/problem/23038
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    char pic[3*n][3*m];
    for(int i=0; i<3*n; ++i)
        for(int j=0; j<3*m; ++j)
            cin >> pic[i][j];
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            bool flag = false;
            if(i > 0){
                flag = true;
                if(pic[i*3-1][j*3+1] == '#')
                    pic[i*3][j*3+1] = '#';
            }
            if(i < n-1){
                flag = true;
                if(pic[i*3+3][j*3+1] == '#')
                    pic[i*3+2][j*3+1] = '#';
            }
            if(j > 0){
                flag = true;
                if(pic[i*3+1][j*3-1] == '#')
                    pic[i*3+1][j*3] = '#';
            }
            if(j < m-1){
                flag = true;
                if(pic[i*3+1][j*3+3] == '#')
                    pic[i*3+1][j*3+2] = '#';
            }
            if(flag){
                pic[i*3+1][j*3+1] = '#';
            }
        }
    }

    for(int i=0; i<3*n; ++i){
        for(int j=0; j<3*m; ++j)
            cout << pic[i][j];
        cout << "\n";
    }
    return 0;
}