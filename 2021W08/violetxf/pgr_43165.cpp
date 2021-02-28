/*
    타겟 넘버
    https://programmers.co.kr/learn/courses/30/lessons/43165
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int result = 0;
vector<int> vec;
int tar;
void dfs(int idx, int sum){
    if(idx == vec.size()){
        if(sum==tar)
            result++;
        return;
    }
    dfs(idx+1, sum+vec[idx]);
    dfs(idx+1, sum-vec[idx]);
}
int solution(vector<int> numbers, int target) {
    result = 0;
    vec = numbers;
    tar = target;
    dfs(0, 0);
    return result;
}
int main(){
    cout<<solution({1,1,1,1,1}, 3);
}