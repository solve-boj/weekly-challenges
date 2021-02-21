/*
    하노이 탑 이동 순서
    https://www.acmicpc.net/problem/11729
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
    ostringstream oss;
    cin >> N;
    cout << hanoi(oss,N,1,3) << "\n";
    cout << oss.str();
}