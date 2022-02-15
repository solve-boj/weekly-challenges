#include <bits/stdc++.h>

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    int memory[101], cost[101];
    int cost_sum = 0;
    for(int i=0; i<n; ++i){
        scanf("%d", &memory[i]);
    }
    for(int i=0; i<n; ++i){
        scanf("%d", &cost[i]);
        cost_sum += cost[i];
    }

    // 남은 앱들의 cost를 최대화
    int dp[10001] = {0,};
    for(int i=0; i<n; ++i){
        for(int j=10000; j>=cost[i]; --j){
            dp[j] = (dp[j] < dp[j-cost[i]]+memory[i]) ? dp[j-cost[i]]+memory[i] : dp[j];
        }
    }

    for(int i=0; i<=10000; ++i){
        if(dp[i]>=m){
            printf("%d", i);
            break;
        }
    }
    return 0;
}