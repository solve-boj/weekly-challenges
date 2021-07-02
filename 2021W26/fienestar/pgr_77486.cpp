/*
    다단계 칫솔 판매
    https://programmers.co.kr/learn/courses/30/lessons/77486
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer(enroll.size() + 1);
    vector<size_t> parent(enroll.size() + 1, enroll.size());
    
    map<string, size_t> idx_of;
    
    idx_of["-"] = enroll.size();
    
    for(size_t i=0; i!=enroll.size(); ++i)
        idx_of[enroll[i]] = i;
    
    for(size_t i=0; i!=referral.size(); ++i)
        parent[i] = idx_of[referral[i]];
    
    for(size_t i=0; i!=seller.size(); ++i){
        auto money = amount[i] * 100;
        auto idx = idx_of[seller[i]];
        do{
            answer[idx] += money - money / 10;
            money = money / 10;
            idx = parent[idx];
        }while(idx != parent[idx]);
    }
    
    answer.resize(enroll.size());
    
    return answer;
}