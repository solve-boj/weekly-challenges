/*
    AND와 OR
    https://www.acmicpc.net/problem/23042
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long digits[31] = {0, }, num;
    for(int i=0; i<N; ++i){
        cin >> num;
        for(int j=0; num; ++j, num >>= 1)
            digits[j] += (num & 1);
    }

    long long arr[N] = {0, };
    for(int i=0; i<31; ++i)
        for(int j=0; j<digits[i]; ++j)
            arr[N-1-j] += (1 << i);

    long long answer = 1;
    for(int i=0; i<N; ++i){
        // 여기 조심해야 함
        // (a*b*c*d*...)%N == (((a%N)*b%N)*c%N)...
        answer *= arr[i];
        answer %= 1000000007;
    }
    cout << answer; 
    return 0;
}