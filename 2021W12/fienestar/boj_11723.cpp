/*
    집합
    https://www.acmicpc.net/problem/11723
*/
#include <bits/stdc++.h>

using namespace std;

constexpr size_t hash(const char* str)
{
    size_t x = 0;
    size_t i = 0;
    for(i=0;str[i];i++)
        x = (1000003*x) ^ str[i];
    return x;
}

constexpr size_t operator""h(const char* str, size_t)
{
    return ::hash(str);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string command;
    size_t M;
    size_t x;
    bool is_in[21];
    
    cin >> M;

    while(M--){
        cin >> command;
        switch(::hash(command.c_str())){
            case "add"h:
                cin >> x;
                is_in[x] = true;
                break;
            case "remove"h:
                cin >> x;
                is_in[x] = false;
                break;
            case "check"h:
                cin >> x;
                cout << is_in[x] << "\n";
                break;
            case "toggle"h:
                cin >> x;
                is_in[x]^=1;
                break;
            case "all"h:
                fill(is_in,is_in+21,true);
                break;
            case "empty"h:
                fill(is_in,is_in+21,false);
                break;
        }
    }
}