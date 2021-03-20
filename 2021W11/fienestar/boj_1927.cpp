/*
    최소 힙
    https://www.acmicpc.net/problem/1927
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N;
    priority_queue<int> pq;

    cin >> N;
    while(N--){
        int v;
        cin >> v;
        if(v)
            pq.push(-v);
        else{
            if(pq.size()){
                cout << -pq.top() << "\n";
                pq.pop();
            }else
                cout << 0 << "\n";
        }
    }
}