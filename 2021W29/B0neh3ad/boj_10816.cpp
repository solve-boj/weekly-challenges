/*
    숫자 카드 2
    https://www.acmicpc.net/problem/10816
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_INT = 20000001;
int cnt[MAX_INT];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    int card;
    for(int i=0; i<N; i++){
        cin >> card;
        cnt[card+10000000]++;
    }

    int M;
    cin >> M;

    int obj;
    for(int i=0; i<M; i++){
        cin >> obj;
        cout << cnt[obj+10000000] << " ";
    }
    return 0;
}