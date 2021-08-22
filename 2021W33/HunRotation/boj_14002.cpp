/*
    가장 긴 증가하는 부분 수열 4
    https://www.acmicpc.net/problem/14002
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> arr;
stack<int> ansarr;
int dp[1000], maxpos[1001];

int f(int pos) {
    //printf("%d\n", pos);
    int res = 1;
    if (pos == 0) return dp[pos] = 1;
    if (dp[pos]) return dp[pos];
    
    for(int i=0;i<pos;i++) {
        int k;
        if(arr[pos] > arr[i])
            if ((k = f(i) + 1) > res) {
                res = max(res, k);
                maxpos[pos] = i;
            }
        //printf("%d %d\n", pos, res);
    }

    return dp[pos] = res;
}
                                                                                                                                                                                                                                                                                         

int main() {
    int t, ans = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        maxpos[i] = i;
        scanf("%d", &t);
        arr.push_back(t);
    }
    for(int i=0;i<N;i++) {
        int k;
        if ((k = f(i)+1) > ans) {
            ans = max(ans, k);
            maxpos[1000]= i;
        }
    }
    int i;
    for(i=maxpos[1000];i != maxpos[i];i = maxpos[i]) {
        ansarr.push(arr[i]);
    }
    ansarr.push(arr[i]);

    printf("%d\n", ans-1);
    while(!ansarr.empty()) {
        printf("%d ", ansarr.top());
        ansarr.pop();
    }
}

// keyword: DP
// 시간복잡도: O(N^2)
/*
idea: pos 앞의 모든 항에 대해 각 항으로 끝나는 최대 길이 증가 부분 수열 구함
pos 위치의 값이 앞 수열의 마지막 항보다 크다면 1을 더한 값을 고려
*/