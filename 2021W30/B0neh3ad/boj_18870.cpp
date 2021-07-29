/*
    좌표 압축
    https://www.acmicpc.net/problem/18870
*/
#include <iostream>
#include <algorithm>
using namespace std;

int old_N, N;
long long inp[1000000], old_X[1000000], X[1000000];

int idx(int x){ return lower_bound(X, X+N, x) - X; }

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> old_N;
    for(int i=0; i<old_N; ++i){
        cin >> inp[i];
        old_X[i] = inp[i];
    }

    // 정렬
    sort(old_X, old_X+old_N);

    // 중복값 제거
    X[0] = old_X[0];
    N = 1;
    for(int i=1; i<old_N; ++i){
        if(old_X[i-1] != old_X[i]){
            X[N] = old_X[i];
            ++N;
        }
    }

    for(int i=0; i<old_N; ++i)
        cout << idx(inp[i]) << " ";

    return 0;
}