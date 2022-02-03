#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(void){
    int n;
    cin >> n;

    ull dist[n-1], price[n];
    for(int i=0; i<n-1; ++i){
        cin >> dist[i];
    }
    for(int i=0; i<n; ++i){
        cin >> price[i];
    }

    ull curr_price = price[0];
    ull ans = 0;
    for(int i=1; i<n; ++i){
        ans += curr_price * dist[i-1];
        if(curr_price > price[i]){
            curr_price = price[i];
        }
    }

    cout << ans;
    return 0;
}