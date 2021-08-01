/*
    입국심사
    https://programmers.co.kr/learn/courses/30/lessons/43238
*/
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0;
    long long right = 1'000'000'000ll*1'000'000'000ll;
    while(left+1<right){
        long long mid = (left+right)/2;
        long long total = 0;
        for(int t: times){
            total += mid/t;
        }
        if(total>=n){
            right = mid;
        } else {
            left = mid;
        }
    }

    return right;
}