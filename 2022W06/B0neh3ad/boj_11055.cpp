#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n], dp[n] = {0, };
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    int ans = 0;
    for(int i=0; i<n; ++i){
        int temp = 0;
        for(int j=0; j<i; ++j){
            if(a[j] < a[i]){
                temp = max(temp, dp[j]);
            }
        }
        dp[i] = temp + a[i];
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}