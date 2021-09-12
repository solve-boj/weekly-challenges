/*
    자연수 색칠하기
    https://www.acmicpc.net/problem/23048
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int K = 1, arr[N+1] = {0, };
    arr[1] = 1;
    for(int i=2; i<=N; ++i){
        if(!arr[i]){
            ++K;
            for(int j=i; j<=N; j+=i)
                arr[j] = K;
        }
    }
    cout << K << "\n";
    for(int i=1; i<=N; ++i)
        cout << arr[i] << " ";
    return 0;
}