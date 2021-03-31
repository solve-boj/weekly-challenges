/*
    색종이 만들기
    https://www.acmicpc.net/problem/2630
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N;
    cin >> N;

    vector<vector<size_t>> paper(N,vector<size_t>(N));
    for(auto& c:paper)
        for(auto& v:c)
            cin >> v;

    size_t wb[3] = {};
    
    function<size_t(size_t,size_t,size_t)> check = [&](size_t x, size_t y, size_t size)->size_t{
        if(size == 1)
            return paper[x][y];
        static size_t dx[] = {1,1,0,0};
        static size_t dy[] = {0,1,0,1};
        size >>= 1;

        size_t result[4];
        bool flag = true;
        
        for(size_t i=0; i!=4; ++i){
            result[i] = check(x+dx[i]*size, y+dy[i]*size, size);
            if(i)
                flag = flag && result[i] == result[i-1];
        }

        if(flag)
            return result[0]; 
        for(size_t i=0; i!=4; ++i)
            ++wb[result[i]];

        return 2;
    };
    ++wb[check(0,0,N)];
    
    cout << wb[0] << "\n" << wb[1];
}