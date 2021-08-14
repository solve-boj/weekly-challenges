/*
    ATM
    https://www.acmicpc.net/problem/11399
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int pi[n];
    for(int i=0; i<n; ++i){ cin >> pi[i]; }

    sort(pi, pi+n);
    
    long long ans = 0;
    for(int i=0; i<n; ++i){
        ans += (n-i)*pi[i];
    }

    cout << ans;
    return 0;
}
/*
    웰노운 그리디 문제
*/