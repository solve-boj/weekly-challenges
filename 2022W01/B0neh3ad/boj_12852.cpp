/*
    1로 만들기 2
    https://www.acmicpc.net/problem/12852
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;

    cin >> n;
    int cnt[n+1] = {0, };
    for(int i=1; i<=n; ++i){
        if(i*3 <= n){
            cnt[i*3] = cnt[i*3] ? min(cnt[i*3], cnt[i]+1) : (cnt[i]+1);
        }
        if(i*2 <= n){
            cnt[i*2] = cnt[i*2] ? min(cnt[i*2], cnt[i]+1) : (cnt[i]+1);
        }
        if(i+1 <= n){
            cnt[i+1] = cnt[i+1] ? min(cnt[i+1], cnt[i]+1) : (cnt[i]+1);
        }
    }
    cout << cnt[n] << "\n";

    int i = n;
    cout << n << " ";
    while(i > 1){
        if(i%3 == 0 && cnt[i/3]+1 == cnt[i]){
            i /= 3;
        }
        else if(i%2 == 0 && cnt[i/2]+1 == cnt[i]){
            i /= 2;
        }
        else{
            i -= 1;
        }
        cout << i << " ";
    }
    
    return 0;
}