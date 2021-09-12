/*
    5의 수난
    https://www.acmicpc.net/problem/23037
*/

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, ans=0;
    scanf("%d", &n);
    while(n) {
        ans += (int) (pow(n%10, 5) +0.1);
        n /= 10;
    }
    printf("%d", ans);
}