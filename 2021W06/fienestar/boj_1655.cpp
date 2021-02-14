/*
    가운데를 말해요
    https://www.acmicpc.net/problem/1655
*/

#include <bits/stdc++.h>

using namespace std;

template <class T, template<class> class F>
auto make_pq()
{
    return priority_queue<T,vector<T>,F<T>>();
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    auto right = make_pq<int,greater>();
    auto left = make_pq<int,less>();

    size_t N;
    cin >> N;
    while(N--){
        int t;
        cin >> t;
        right.push(t);
        left.push(right.top());
        right.pop();
        if(right.size() < left.size()){
            right.push(left.top());
            left.pop();
            cout << right.top() << "\n";
        }else
            cout << min({left.top(),right.top()}) << "\n";
    }
}