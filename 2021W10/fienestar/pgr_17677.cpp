/*
    뉴스 클러스터링
    https://programmers.co.kr/learn/courses/30/lessons/17677
*/
#include <bits/stdc++.h>

using namespace std;
using count_t = size_t[1024];

void check(count_t& arr,string s)
{
    cout << s << ": ";
    for(size_t i=1;i!=s.size();++i)
        if(isalpha(s[i-1]) && isalpha(s[i])){
            char a = toupper(s[i-1]) - 'A';
            char b = toupper(s[i  ]) - 'A';
            ++arr[(a << 5) + b];
            cout << s[i-1] << s[i] << " ";
        }
}

size_t get_sum(const count_t& arr1,const count_t& arr2,function<size_t(size_t,size_t)> f)
{
    size_t result = 0;
    for(size_t i=0;i!=1024;++i)
        result += f(arr1[i],arr2[i]);
    return result;
}

int solution(string str1, string str2)
{
    count_t str1_cnt = {};
    count_t str2_cnt = {};
    
    check(str1_cnt,str1);
    check(str2_cnt,str2);
    size_t n = get_sum(str1_cnt,str2_cnt,[](size_t a,size_t b){return min(a,b);});
    size_t u = get_sum(str1_cnt,str2_cnt,[](size_t a,size_t b){return max(a,b);});
    
    if(u == 0)
        return 65536;
    
    return 65536*n/u;
}