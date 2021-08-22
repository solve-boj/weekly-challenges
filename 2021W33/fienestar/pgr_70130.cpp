/*
    스타 수열
    https://programmers.co.kr/learn/courses/30/lessons/70130
*/
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a)
{
    vector<size_t> last(a.size(), -1); 
    vector<size_t> count(a.size());
    size_t M = 0;
    
    for(size_t i=0; i!=a.size(); ++i)
        for(size_t j=i-1; j!=i+3; j+=2)
            if(j < a.size() && a[j] != a[i] && last[a[i]]!=j) {
                last[a[i]] = j;
                M = max(M, ++count[a[i]]);
                break;
            }
    
    return M * 2;
}