/*
    잠수함식별
    https://www.acmicpc.net/problem/2671
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    regex re("(100+1+|01)+");
    cmatch m;
    string in;
    cin >> in;
    cout << (regex_match(in.c_str(),m,re) ? "SUBMARINE" : "NOISE");
}