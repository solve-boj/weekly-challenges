#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, b;
    cin >> n >> m >> b;

    int h[n][m];
    int bsum = b;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> h[i][j];
            bsum += h[i][j];
        }
    }

    int ans, time = 1000000000;
    for(int i=0; i*n*m<=bsum && i<=256; ++i){
        int temp = 0;
        for(int y=0; y<n; ++y){
            for(int x=0; x<m; ++x){
                temp += (h[y][x] > i) ? 2*(h[y][x] - i) : (i - h[y][x]);
            }
        }
        if(time >= temp){
            time = temp;
            ans = i;
        }
    }

    cout << time << " " << ans;

    return 0;
}