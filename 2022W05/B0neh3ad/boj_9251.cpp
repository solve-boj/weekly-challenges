#include <bits/stdc++.h>
using namespace std;
char str1[1001], str2[1001];
int n, m;

int main(void){
    scanf("%s %s", str1, str2);
    n = strlen(str1);
    m = strlen(str2);

    int dp[n+1][m+1];
    for(int i=0; i<=n; ++i){ fill(dp[i], dp[i]+m+1, 0); }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    cout << dp[n][m];

    return 0;
}