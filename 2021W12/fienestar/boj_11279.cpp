/*
    최대 힙
    https://www.acmicpc.net/problem/11279
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<size_t> pq;

    size_t N;
    cin >> N;

    size_t x;
    while(N--){
        cin >> x;
        if(x)
            pq.push(x);
        else{
            if(pq.size()){
                cout << pq.top() << "\n";
                pq.pop();
            }else
                cout << 0 << "\n";
        }
    }
}