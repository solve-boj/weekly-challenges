/*
    주식가격
    https://programmers.co.kr/learn/courses/30/lessons/42584?language=cpp#
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    vector<pair<int,int>> stack;
    stack.push_back({prices[0], 0});
    for(int i=1;i<prices.size();i++){
        if(prices[i]>=stack.back().first){
            stack.push_back({prices[i], i});
        } else {
            while(!stack.empty()){
                int back = stack.back().first;
                int pos = stack.back().second;
                if(back<=prices[i])break;
                else {
                    stack.pop_back();
                    if(answer[pos]==0)
                        answer[pos] = i-pos;
                }
            }
            stack.push_back({prices[i],i});
        }
    }
    while(!stack.empty()){
        int back = stack.back().first;
        int pos = stack.back().second;
        answer[pos] = prices.size()-pos-1;
        stack.pop_back();
    }
    return answer;
}
int main(){
    vector<int> result = solution({3,4,3,2,5});
    for(int k: result){
        cout<<k<<" ";
    }
    
}