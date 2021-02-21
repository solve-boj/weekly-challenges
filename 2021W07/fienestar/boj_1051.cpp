/*
    숫자 정사각형
    https://www.acmicpc.net/problem/1051
*/

#include <bits/stdc++.h>

using namespace std;

size_t find_sum_max(vector<vector<size_t>>& v,size_t len)
{
    size_t sum_max = 0;
    for(size_t i=len;i!=v.size();++i)
        for(size_t j=len;j!=v[i].size();++j)
            sum_max = max({sum_max,v[i-len][j-len]+v[i-len][j]+v[i][j-len]+v[i][j]});
    return sum_max;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N,M;
    cin >> N >> M;
    vector<vector<size_t>> v(N,vector<size_t>(M));

    for(auto& i:v)
        for(auto& j:i)
            cin >> j;

    size_t sum_max = 0;
    size_t sum_max_len = 0;

    for(size_t i=min({N,M})+1;--i;){
        size_t sum = find_sum_max(v,i);
        if(sum > sum_max){
            sum_max = sum;
            sum_max_len = i;
        }
    }
}