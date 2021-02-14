/*
    Ax+Bsin(x)=C ②
    https://www.acmicpc.net/problem/14786
*/

#include <bits/stdc++.h>

using namespace std;
using llf = long double;

int main()
{
    llf A,B,C;
    cin >> A >> B >> C;

    llf begin = (C-B)/A;
    llf end = (C+B)/A;
    
    auto f = [A,B,C](llf x)->llf{return A * x + B * sin(x) - C;};

    while(abs(f(begin)) > 1e-10){
        llf av = (begin+end)/2;

        auto old = make_pair(begin,end);

        if(f(av) > 0)
            end = av;
        else
            begin = av;

        if(old == make_pair(begin,end))break;
    }
    cout << setprecision(22) << begin;
}