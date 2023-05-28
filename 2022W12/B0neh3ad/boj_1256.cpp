#include <bits/stdc++.h>
using namespace std;

long long c[201][101];

long long comb(int n, int m){
    if(n < m){
        return 0;
    }

    if(m==0 || m==n){
        c[n][m] = 1;
    }
    if(c[n][m]){
        return c[n][m];
    }

    c[n][m] = comb(n-1, m) + comb(n-1, m-1);
    if(c[n][m] > INT_MAX){ c[n][m] = INT_MAX; }
    return c[n][m];
}

void sol(int n, int m, int k){
    char ans[n+m];
    int len = n+m-1, z_cnt = m;

    if(k > comb(n+m, z_cnt)){
        cout << -1;
        return;
    }

    for(int i=0; i<n+m-1; ++i){
        if(k > comb(len, z_cnt)){
            ans[i] = 'z';
            k -= comb(len, z_cnt);
            --z_cnt;
        }
        else{
            ans[i] = 'a';
        }

        --len;
    }

    ans[n+m-1] = z_cnt ? 'z' : 'a';

    for(char& c: ans){
        cout << c;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;
    sol(n, m, k);

    return 0;
}