/*
    나는야 포켓몬 마스터 이다솜
    https://www.acmicpc.net/problem/1620
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N,M;
    cin >> N >> M;
    
    vector<string> name(N+1);
    map<string, size_t> no;

    for(size_t i=1; i<=N; ++i){
        cin >> name[i];
        no.emplace(name[i],i);
    }

    string q;
    while(M--){
        cin >> q;
        if(isdigit(q[0]))
            cout << name[stol(q)] << "\n";
        else
            cout << no[q] << "\n";
    }
}