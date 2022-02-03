#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    int seq[n];
    for(int i=0; i<n; ++i){ cin >> seq[i]; }

    int st[n] = {0, };
    int idx = 0;

    int ans[n];

    for(int i=0; i<n; ++i){ ans[i] = -1; }
    
    for(int i=n-1; i>=0; --i){
        while(idx > 0){
            // 위에 있을수록 현재 elem의 위치와 가까운 것
            if(st[--idx] > seq[i]){
                ans[i] = st[idx++];
                break;
            }
        }

        // after all...
        st[idx++] = seq[i];
    }

    for(int i=0; i<n; ++i){ cout << ans[i] << " "; }

    return 0;
}