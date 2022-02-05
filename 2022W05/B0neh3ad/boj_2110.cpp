#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    int loc[n];
    for(int i=0; i<n; ++i){
        cin >> loc[i];
    }

    sort(loc, loc+n);

    int s = 1, e = 1000000001;
    while(s+1 < e){
        // cout << "s: " << s << " e: " << e << "\n";
        int mid = (s+e)/2;
        int cnt = 1, prev = loc[0];
        for(int i=1; i<n; ++i){
            if(loc[i] - prev >= mid){
                ++cnt;
                prev = loc[i];
            }
        }
        if(cnt >= c){
            s = mid;
        }
        else {
            e = mid;
        }
    }

    cout << s;
    return 0;
}