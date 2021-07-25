/*
    신기한 연산
    https://www.acmicpc.net/problem/19846
*/
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;

    int s, e;
    for(int i=0; i<q; i++)
        cin >> s >> e;

    for(int i=0; i<m; i++)
        cout << char(int((i % (2*n)) / 2) + 97);
}