/*
    소수 만들기
    https://programmers.co.kr/learn/courses/30/lessons/12977
*/
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    // set primes
    int primes[3001] = {0, };
    for(int i=2; i*i<=3000; ++i)
        for(int j=i*i; j<=3000; j+=i)
            primes[j] = 1;
    // get answer
    for(int i=0; i<nums.size()-2; ++i)
        for(int j=i+1; j<nums.size()-1; ++j)
            for(int k=j+1; k<nums.size(); ++k)
                if(!primes[nums[i]+nums[j]+nums[k]])
                    ++answer;
    return answer;
}