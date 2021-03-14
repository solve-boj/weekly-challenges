/*
    3의 배수
    https://www.acmicpc.net/problem/1769
*/
#include <bits/stdc++.h>

using namespace std;

string sum(string n)
{
    size_t result = 0;
    for(auto c:n)
        result += c-'0';
    return to_string(result);
}

int main()
{
    string n;
    cin >> n;

    size_t cnt = 0;
    while(n.size() != 1){
        n = sum(n);
        ++cnt;
    }

    cout << cnt << "\n";
    if(n[0] % 3)
        cout << "NO";
    else
        cout << "YES";
}