#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ull n, k;
    cin >> n >> k;

    ull s = 0, e = k;
    while(s+1 < e){
        // cout << s << " " << e << "\n";
        ull mid = (s+e) / 2;

        ull cnt = 0;
        for(ull i=1; i<=n; ++i){
            cnt += min(mid/i, n);
        }

        if(cnt >= k){
            e = mid;
        }
        else {
            s = mid;
        }
    }

    cout << e;
    return 0;
}