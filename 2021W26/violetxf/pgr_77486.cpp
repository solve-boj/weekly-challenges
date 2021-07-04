/*
    다단계 칫솔 판매
    https://programmers.co.kr/learn/courses/30/lessons/77486
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    map<string, int> indices;

    for(int i=0;i<enroll.size();i++){
        indices[enroll[i]] = i;
    }
    indices["-"] = -1;
    vector<int> ref_indices(enroll.size(),-1);

    for(int i=0;i<referral.size();i++){
        ref_indices[indices[enroll[i]]] = indices[referral[i]];
    }
    
    for(int i=0;i<seller.size();i++){
        int ref = ref_indices[indices[seller[i]]];
        int price = amount[i] * 100;
        int earning = price;
        int up = price/10;
        earning -= up;
        answer[indices[seller[i]]] += earning;
        while (ref>-1 && up>0){
            answer[ref] += up - up/10;
            up/=10;
            ref = ref_indices[ref];
        }
    }
    return answer;
}