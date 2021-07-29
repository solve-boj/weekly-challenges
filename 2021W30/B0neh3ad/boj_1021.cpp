/*
    회전하는 큐
    https://www.acmicpc.net/problem/1021
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int q[N];
    for(int i=0; i<N; ++i)
        q[i] = i+1;

    int p = 0;
    int result = 0, select;
    for(int i=0; i<M; ++i){
        cin >> select;
        int temp = 0;
        while(q[p] != select){
            p = (p+1) % N;
            ++temp;
            while(!q[p]){ p = (p+1) % N; }
        }
        result += min(temp, (N-i)-temp);
        q[p] = 0; // 이미 뽑은 것 표시
        p = (p+1) % N;
        if(i == M-1){ break; }
        while(!q[p]){ p = (p+1) % N; } // 다음 칸으로..
    }

    cout << result;
    return 0;
}