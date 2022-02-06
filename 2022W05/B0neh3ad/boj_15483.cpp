#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a;
    cin >> b;

    int a_len = a.size(), b_len = b.size();

    for(int i=1; i<=a_len; ++i){ dp[i][0] = i; }
    for(int i=1; i<=b_len; ++i){ dp[0][i] = i; }

    for(int i=1; i<=a_len; ++i){
        for(int j=1; j<=b_len; ++j){
            dp[i][j] = dp[i-1][j-1];
            if(a[i-1] != b[j-1]){
                dp[i][j] += 1;
            }
            dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1])+1);
        }
    }

    cout << dp[a_len][b_len];
    return 0;
}