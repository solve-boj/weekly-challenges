/*
    뛰는 기물
    https://www.acmicpc.net/problem/23041
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long n, m;
    cin >> n >> m;

    long long gcd = __gcd(n, m);
    n /= gcd; m /= gcd;
    long long answer = gcd*gcd;

    if(n%2 && m%2){ answer *= 2; }
    cout << answer;
    return 0;
}