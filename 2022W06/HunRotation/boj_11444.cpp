/*
    피보나치 수 6
    https://www.acmicpc.net/problem/11444
*/

#include <iostream>
#include <map>

using namespace std;

long long n;
map<long long, long long> m;

long long f(long long k) {
    if(m.find(k) != m.end()) {
        return m[k];
    }
    m[k] = (f(k/2-1)*f(k-k/2) + f(k/2)*f(k-k/2+1)) % 1000000007;
    return m[k];
}

int main() {
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;
    m[3] = 2;
    scanf("%lld", &n);
    printf("%lld", f(n));
}