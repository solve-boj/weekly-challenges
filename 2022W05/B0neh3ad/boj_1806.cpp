#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    int seq[N];
    int psum[N+1] = {0, };
    for(int i=0; i<N; ++i){
        cin >> seq[i];
        psum[i+1] = psum[i] + seq[i];
    }

    int s = 1, e = 1;
    int ans = INT_MAX;
    while(s <= N && e <= N){
        if(psum[e] - psum[s-1] >= S){
            ans = min(ans, e-s+1);
            ++s;
        }
        else{
            ++e;
        }
    }
    if(ans == INT_MAX){ ans = 0; }
    cout << ans;
    return 0;
}