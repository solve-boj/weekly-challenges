/*
    듣보잡
    https://www.acmicpc.net/problem/1764
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t N,M;
    cin >> N >> M;

    string name;
    set<string> m;
    while(N--){
        cin >> name;
        m.insert(name);
    }

    set<string> result;
    while(M--){
        cin >> name;
        if(m.find(name) != m.end())
            result.insert(name);
    }

    cout << result.size() << "\n";
    for(auto& name:result)
        cout << name << "\n";
}