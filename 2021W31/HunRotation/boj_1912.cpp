/*
    연속합
    https://www.acmicpc.net/problem/1912
*/


#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[100000];
long long sum[100000];
int main() {
    int n;
    long long ans;
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%lld", &arr[i]);
        if (i==0) {
            ans = sum[i] = arr[i];
        }
        else {
            sum[i] = max(arr[i], sum[i-1] + arr[i]);
            if (ans < sum[i]) {
                ans = sum[i];
            }
        }
    }
    printf("%lld", ans);
}


// keyword: DP
// 시간복잡도: O(n)
/*
idea: sum[i]는 arr[i]를 구간의 끝으로 하는 부분합 중 최댓값을 의미
sum[i+1]을 구할 때 sum[i]가 음수이면 이전의 수를 어떻게 더해도 구간 합을 감소시킬 뿐이므로
아얘 arr[i]를 넣어 새로 시작(최대 구간합의 시작점을 arr[i]로 잡음)
*/