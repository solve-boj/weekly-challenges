/*
    정수 삼각형
    https://www.acmicpc.net/problem/1932
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    // 이거 안 쓰면 44ms, 쓰면 12ms ㅋㅋ
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int tri[n][n];
    for(int i=0; i<n; ++i){
        for(int j=0; j<=i; ++j){
            cin >> tri[i][j];
        }
    }

    int costs[n][n] = {0, }; // 최대 경로 저장 배열
    costs[0][0] = tri[0][0];
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<=i; ++j){
            costs[i+1][j] = max(costs[i+1][j], costs[i][j]+tri[i+1][j]);
            costs[i+1][j+1] = max(costs[i+1][j+1], costs[i][j]+tri[i+1][j+1]);
        }
    }

    int ans = 0;
    for(int i=0; i<n; ++i){
        ans = max(ans, costs[n-1][i]);
    }

    cout << ans;
    return 0;
}