#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    int sol[n];
    for(int i=0; i<n; ++i){
        cin >> sol[i];
    }

    sort(sol, sol+n);

    int s=0, e=n-1;
    int curr;
    int ans[2], ans_val = INT_MAX;
    while(s<e){
        curr = sol[s] + sol[e];
        if(abs(curr) < ans_val){
            ans_val = abs(curr);
            ans[0] = s;
            ans[1] = e;
        }
        if(curr > 0){
            --e;
        }
        else{
            ++s;
        }
    }

    cout << sol[ans[0]] << " " << sol[ans[1]];
    return 0;
}