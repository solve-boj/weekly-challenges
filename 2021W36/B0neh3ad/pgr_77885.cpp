/*
    2개 이하로 다른 비트
    https://programmers.co.kr/learn/courses/30/lessons/77885
*/
#include <bits/stdc++.h>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long& num: numbers){
        long long z = 1, t = num;
        while(t & 1){ t >>= 1; z <<= 1; }
        answer.push_back(num + (z >> 1) + (z <= 1));
    }
    return answer;
}
/*
    숏코딩 ON
*/