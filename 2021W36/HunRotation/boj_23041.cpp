/*
    뛰는 기물
    https://www.acmicpc.net/problem/23041
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int n, m;
int ans;

int gcd(int a, int b) {
    if (a<b) swap(a, b);
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    scanf("%d %d", &N, &M);
    n = N/gcd(N, M);
    m = M/gcd(N, M);
    if(n%2==0 || m%2==0) ans = 1;
    else ans = 2;
    printf("%lld", (long long) ans*gcd(N,M)*gcd(N,M));
}