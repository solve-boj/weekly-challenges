/*
    ATM
    https://www.acmicpc.net/problem/11399
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t N;
    cin >> N;
    
    vector<int> v(N);
    for(auto& c:v)
        cin >> c;
    
    sort(v.begin(),v.end());

    size_t sum = 0;
    size_t answer = 0;

    for(auto& c:v){
        sum += c;
        answer += sum;
    }
    
    cout << answer;
}