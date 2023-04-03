#include <bits/stdc++.h>
using namespace std;

int arr[200000];

void sol(int s, int level, bool order){
    if(level < 0){ return; }

    int n = pow(2, level);
    for(int i=0; i<n; ++i){
        arr[s+i] |= (!order << level);
    }
    sol(s, level-1, true);
    for(int i=n; i<2*n; ++i){
        arr[s+i] |= (order << level);
    }
    sol(s+n, level-1, false);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int k = pow(2, n) - 1;
    cout << k << '\n';

    sol(0, n-1, true);

    for(int i=0; i<k; ++i){
        cout << log2(arr[i] ^ arr[i+1]) + 1 << '\n';
    }
    cout << log2(arr[k]) + 1;
    return 0;
}