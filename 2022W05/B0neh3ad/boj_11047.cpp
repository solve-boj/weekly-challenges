#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int coins[n];
    for(int i=0; i<n; ++i){
        cin >> coins[i];
    }

    int ans = 0;
    for(int i=n-1; k>0, i>=0; --i){
        ans += (k / coins[i]);
        k %= coins[i];
    }

    cout << ans;
    return 0;
}