/*
    단어 정렬
    https://www.acmicpc.net/problem/1181
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b){
    return ((a.length() == b.length()) ? (a < b) : (a.length() < b.length()));
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string lst[N];
    for(int i=0; i<N; ++i){ cin >> lst[i]; }
    sort(lst, lst+N, cmp);

    cout << lst[0] << endl;
    for(int i=1; i<N; ++i){
        if(lst[i] != lst[i-1])
            cout << lst[i] << endl;
    }
    return 0;
}