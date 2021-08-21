/*
    가장 큰 증가 부분 수열
    https://www.acmicpc.net/problem/11055
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> arr;
int dp[1000];

int f(int pos) {
    //printf("%d\n", pos);
    int res = arr[pos];
    if (pos == 0) return dp[pos] = arr[pos];
    if (dp[pos]) return dp[pos];

    for(int i=0;i<pos;i++) {
        if(arr[pos] > arr[i])
            res = max(res, f(i) + arr[pos]);
        //printf("%d %d\n", pos, res);
    }
    
    return dp[pos] = res;
}
                                                                                                                                                                                                                                                                                         

int main() {
    int t, ans = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &t);
        arr.push_back(t);
    }
    for(int i=0;i<N;i++) {
        ans = max(ans, f(i));
    }
    printf("%d", ans);
}

// keyword: DP
// 시간복잡도: O(N^2)
/*
idea: pos 앞의 모든 항에 대해 각 항으로 끝나는 최대 합 증가 부분 수열 구함
pos 위치의 값이 앞 수열의 마지막 항보다 크다면 pos를 더한 값을 고려
*/