#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int comb[30][30];

int sol(int n, int r){
    if(comb[n][r]){
        return comb[n][r];
    }

    comb[n][r] = sol(n-1, r-1) + sol(n-1, r);
    return comb[n][r];
}

int main(void){
    int t;
    cin >> t;

    for(int i=0; i<30; ++i){
        comb[i][0] = comb[i][i] = 1;
    }

    while(t--){
        int n, m;
        cin >> n >> m;

        cout << sol(m, n) << '\n';
    }

    return 0;
}