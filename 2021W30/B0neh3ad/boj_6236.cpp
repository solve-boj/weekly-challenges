/*
    용돈 관리
    https://www.acmicpc.net/problem/6236
*/
#include <iostream>
using namespace std;

int N, M;
int money[100000];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; ++i)
        cin >> money[i];
    
    // (불만족, 만족]
    int s = 0, e = 1000000000;
    while(s+1 < e){
        int mid = (s+e) / 2;
        int cnt = 0, remain = 0;
        for(int i=0; i<N; ++i){
            if(mid < money[i]){
                cnt = M+1;
                break;
            }
            if(remain < money[i]){
                ++cnt;
                remain = mid;
            }
            remain -= money[i];
        }
        if(cnt <= M){ e = mid; } // 만족
        else{ s = mid; } // 불만족
    }

    cout << e;

    return 0;
}