#include <bits/stdc++.h>
using namespace std;

int dp[30][30];

int main(void){
    string str;
    cin >> str;

    int n = str.size();
    for(int l=1; l<=n; ++l){
        for(int s=0; s+l<=n; ++s){
            int e = s+l-1;
            if(l == 1){
                dp[s][e] = 1;
            }
            else{
                int lhs=s, rhs=e;
                dp[s][e] = 2;
                // 오른쪽 끝 포함
                for(lhs=s+1; lhs<e; ++lhs){
                    if(str[lhs] == str[e]){
                        dp[s][e] += dp[lhs+1][e-1]+1;
                    }
                }
                // 왼쪽 끝 포함
                for(rhs=e-1; rhs>s; --rhs){
                    if(str[s] == str[rhs]){
                        dp[s][e] += dp[s+1][rhs-1]+1;
                    }
                }
                /* below is complete */
                // 양 끝 포함 X
                dp[s][e] += dp[s+1][e-1];
                // 양 끝 모두 포함
                dp[s][e] += (dp[s+1][e-1]+1) * (str[s] == str[e]);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}