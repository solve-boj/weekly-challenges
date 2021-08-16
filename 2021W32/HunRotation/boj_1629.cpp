/*
    곱셈
    https://www.acmicpc.net/problem/1629
*/

#include <cstdio>

using namespace std;

long long a,b,c;

long long f(long long A, long long B, long long C) {
    if (B==1) {
        return A % C;
    }
    long long res = f(A, B/2, C);
    return res * res % C * (B%2?A:1) % C;
}

int main() {
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", f(a, b, c));
}

// keyword: 분할 정복
// 시간복잡도: O(log b)
/*
idea: (A^N) = (A^(N/2))^2 (N 짝수)
홀수일 때는 여기에 한번 더 곱함
*/