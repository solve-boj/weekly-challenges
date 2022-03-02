/*
    정수 삼각형
    https://programmers.co.kr/learn/courses/30/lessons/43105
*/
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = triangle[0][0];
    for(int i=1; i<n; ++i){
        for(int j=0; j<=i; ++j){
            if(j>0){ dp[i][j] = max(dp[i][j], dp[i-1][j-1] + triangle[i][j]); }
            if(j<i){ dp[i][j] = max(dp[i][j], dp[i-1][j] + triangle[i][j]); }
        }
    }

    for(int i=0; i<n; ++i){
        answer = max(answer, dp[n-1][i]);
    }
    return answer;
}

int main(void){
    cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}});
    return 0;
}