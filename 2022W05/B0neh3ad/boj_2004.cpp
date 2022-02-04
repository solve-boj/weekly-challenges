#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(void){
    ull n, m;
    cin >> n >> m;

    ull nume = 0, deno = 0;
    ull lhs_n, rhs_n;
    ull lhs_d, rhs_d;

    // nume
    lhs_n = 0;
    for(ull temp = 2; temp<=n; temp*=2){
        lhs_n += n / temp;
    }
    rhs_n = 0;
    for(ull temp = 5; temp<=n; temp*=5){
        rhs_n += n / temp;
    }

    // deno
    lhs_d = 0;
    for(ull temp = 2; temp<=max(m, n-m); temp*=2){
        lhs_d += m / temp + (n-m) / temp;
    }
    rhs_d = 0;
    for(ull temp = 5; temp<=max(m, n-m); temp*=5){
        rhs_d += m / temp + (n-m) / temp;
    }

    cout << min(lhs_n-lhs_d, rhs_n-rhs_d);

    return 0;
}