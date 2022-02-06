#include <bits/stdc++.h>

int dp[2000][2000];

int main(void){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
    }

    for(int l=0; l<n; ++l){
        for(int s=0; s+l<n; ++s){
            int e = s+l;
            dp[s][e] = (arr[s] == arr[e] && (l <= 1 || dp[s+1][e-1]));
        }
    }

    int m;
    scanf("%d", &m);

    for(int i=0; i<m; ++i){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[--s][--e]);
    }
    return 0;
}