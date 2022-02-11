#include <bits/stdc++.h>

int main(void){
    int lhs[1000], rhs[5]={1,0,0,0,1};
    int ans[1010] = {0, };

    char inp[1001];
    scanf("%s", inp);

    int n = strlen(inp);
    for(int i=0; i<n; ++i){
        lhs[n-1-i] = (inp[i] - '0');
    }

    for(int i=0; i<5; ++i){
        for(int j=0; j<n; ++j){
            ans[i+j] += lhs[j]*rhs[i];
        }
    }

    for(int i=0; i<n+5; ++i){
        if(ans[i] > 1){
            ans[i+1] += ans[i] / 2;
            ans[i] = ans[i] % 2;
        }
    }

    int idx = n+5;
    while(!ans[idx] && idx > 0){ --idx; }
    while(idx >= 0){
        printf("%d", ans[idx--]);
    }

    return 0;
}