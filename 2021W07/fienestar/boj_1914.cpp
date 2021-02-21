/*
    하노이 탑
    https://www.acmicpc.net/problem/1914
*/

#include <bits/stdc++.h>

using namespace std;

size_t other(size_t a,size_t b)
{
    return 6 - a - b;
}

size_t hanoi(ostream& os,size_t n,size_t src, size_t dst)
{
    if(n == 1){
        os << src << " " << dst << "\n";
        return 1;
    }
    
    size_t cnt = 1;
    cnt += hanoi(os,n-1,src,other(src,dst));
    os << src << " " << dst << "\n";
    cnt += hanoi(os,n-1,other(src,dst),dst);
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N;
    cin >> N;
    
    {
        ostringstream oss;
        oss << fixed << setprecision(0) << floorl(powl(2,N));
        string s = oss.str();
        --s[s.size()-1];
        cout << s << "\n";
    }

    if(N<=20){
        ostringstream oss;
        hanoi(oss,N,1,3);
        cout << oss.str();
    }
}