#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(void){
    ull k, x;
    cin >> x >> k;

    ull diff = x - k, res = k*7;
    if(diff >= k*6){
        res *= 1000;
    }
    else if(diff >= k*5/2){
        res *= 500;
    }
    else if(diff >= k*3/4){
        res *= 250;
    }
    else{
        res *= 0;
    }

    cout << res;
    return 0;
}