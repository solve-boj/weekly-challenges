/*
    자원 캐기
    https://www.acmicpc.net/problem/14430
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N,M;
    cin >> N >> M;

    vector<vector<size_t>> res(N,vector<size_t>(M));

    for(auto& c:res)
        for(auto& e:c)
            cin >> e;

    for(size_t i=0;i!=N;++i)
        for(size_t j=0;j!=M;++j){
            size_t m = 0;
            if(i)m = res[i-1][j];
            if(j)m = max(m,res[i][j-1]); 
            res[i][j] += m;
        }
    cout << res[N-1][M-1];
}