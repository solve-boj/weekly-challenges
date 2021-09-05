/*
    연속합
    https://www.acmicpc.net/problem/1912
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool cmp(const pii& lhs, const pii& rhs){ return (lhs.first == rhs.first) ? (lhs.second > rhs.second) : (lhs.first > rhs.first); }

int main(void){
    int n;
    scanf("%d", &n);

    int arr[n];
    int old_presum[n+1] = {0, };
    pii presum[n+1];
    for(int i=0; i<=n; ++i){ presum[i] = pii(0, i); }

    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
        presum[i+1].first = old_presum[i+1] += old_presum[i] + arr[i];
    }
    sort(presum, presum+n+1, cmp);

    int idx = 0, ans = -10000;
    for(int i=0; i<n; ++i){
        while(i >= presum[idx].second){ ++idx; }
        ans = max(ans, presum[idx].first - old_presum[i]);
    }
    cout << ans;
    return 0;
}
/*
    two pointer 같은 느낌
*/