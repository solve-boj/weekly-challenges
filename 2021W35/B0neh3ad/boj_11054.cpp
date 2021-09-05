/*
    가장 긴 바이토닉 부분 수열
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n], rev_arr[n];
    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
        rev_arr[n-1-i] = arr[i];
    }
    int dp[n], rev_dp[n];
    int res = 0;
    for(int i=0; i<n; ++i){
        dp[i] = 1;
        for(int j=0; j<i; ++j){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    for(int i=0; i<n; ++i){
        rev_dp[i] = 1;
        for(int j=0; j<i; ++j){
            if(rev_arr[j] < rev_arr[i]){
                rev_dp[i] = max(rev_dp[j] + 1, rev_dp[i]);
            }
        }
    }
    for(int i=0; i<n; ++i){
        res = max(res, dp[i]+rev_dp[n-1-i]-1);
    }
    cout << res;
    return 0;
}
/*
    그냥... 증가수열 구하고
    뒤집어서 구하고
    더하면 끝

    시간복잡도는 O(n^2)이라서 n 커지면 개선 필요할 듯
    (세그 트리?)
*/