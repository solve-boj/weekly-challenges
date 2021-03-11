#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    regex re("(100+1+|01)+");
    cmatch m;
    string in;
    size_t T;

    cin >> T;
    while(T--){
        cin >> in;
        cout << (regex_match(in.c_str(),m,re) ? "YES\n" : "NO\n");
    }
}