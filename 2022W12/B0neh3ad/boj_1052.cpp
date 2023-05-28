#include <bits/stdc++.h>
using namespace std;

int min_bottles(int init){
    int ans = 0;
    while(init){
        ans += init & 1;
        init >>= 1;
    }
    return ans;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int ans = 0;
    while(min_bottles(n + ans) > k){
        ++ans;
    }

    cout << ans;
    return 0;
}