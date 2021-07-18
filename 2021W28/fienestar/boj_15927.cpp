/*
    회문은 회문아니야!!
    https://www.acmicpc.net/problem/15927
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;

    bool is_c = true;
    for (auto c : s)
        is_c &= (c == s[0]);

    if (is_c)
        cout << -1;
    else {
        bool is_palin = true;
        for (size_t i = 0; i * 2 < s.size(); ++i) 
            is_palin &= s[i] == s[s.size() - 1 - i];
        cout << s.size() - is_palin;
    }
}