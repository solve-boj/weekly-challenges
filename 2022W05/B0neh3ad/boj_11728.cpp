#include <bits/stdc++.h>

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n], b[m];
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<m; ++i){
        scanf("%d", &b[i]);
    }

    int lhs = 0, rhs = 0;
    while(lhs < n && rhs < m){
        printf("%d ", (a[lhs] < b[rhs]) ? a[lhs++] : b[rhs++]);
    }
    while(lhs < n){
        printf("%d ", a[lhs++]);
    }
    while(rhs < m){
        printf("%d ", b[rhs++]);
    }
    return 0;
}