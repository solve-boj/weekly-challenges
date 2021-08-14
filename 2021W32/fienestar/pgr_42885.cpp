/*
    구명보트
    https://programmers.co.kr/learn/courses/30/lessons/42885
*/
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit)
{
    sort(people.rbegin(), people.rend());
    
    auto l = people.begin();
    auto r = people.end() - 1;
    size_t count = 0;
    
    while(l < r)
    {
        if(*l++ + *r <= limit)
            --r;
        ++count;
    }
    
    return count + (l == r);
}