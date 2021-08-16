/*
    부분배열 고르기
    https://www.acmicpc.net/problem/2104
*/

#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[100001], N;

long long getMaxScore(int left, int right) {
    if (left > right) {
        return 0;
    }
    if (left == right) {
        return arr[left] * arr[left];
    }
    int mid = (left + right) / 2;
    int l = mid, r = mid;
    long long maxscore = arr[mid]*arr[mid], cursum = arr[mid], curmin = arr[mid];
    while(r-l < right - left) { // 두 움직이는 변수 차이가 구간 크기보다 작은 동안 계속 반복
    // 코드의 길이 줄일 수 있음
        long long a = l>left ? arr[l-1] : -1;
        long long b = r<right ? arr[r+1] : -1;
        if (a >= b) {
            l--;
            cursum += a;
            curmin = min(curmin, a);
        }
        else {
            r++;
            cursum += b;
            curmin = min(curmin, b);
        }
        maxscore = max(maxscore, cursum*curmin);
    
    }

    return max(max(getMaxScore(left, mid-1), getMaxScore(mid+1, right)), maxscore);  
}

int main() {
    scanf("%lld", &N);
    for(int i=1;i<=N;i++) {
        scanf("%lld", &arr[i]);
    }
    printf("%lld", getMaxScore(1, N));
}


// keyword: 분할 정복
// 시간복잡도: O(N log N)
/*
idea: 주어진 배열의 가운데를 기준으로 잡음
양쪽의 두 배열에서 최대 score를 구함
가운데 원소를 포함한 최대 score를 구함, 이 때 구간을 점수 큰 쪽으로 한 원소씩 늘려나가며 최대 점수 찾음
세 값 중 가장 큰 것을 반환
*/