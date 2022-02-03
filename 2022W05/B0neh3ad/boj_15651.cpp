#include <bits/stdc++.h>

int n, m;
char ans[20];

void sol(int len){
    if(len == m){
        puts(ans);
        return;
    }

    for(int i=1; i<=n; ++i){
        ans[2*len] = '0'+i;
        ans[2*len+1] = ' ';
        sol(len+1);
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    ans[2*m] = 0;
    sol(0);
    return 0;
}