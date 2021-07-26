/*
    입국심사
    https://programmers.co.kr/learn/courses/30/lessons/43238
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long s = 0, e = 1000000000000000000;
    long long mid;
    while(s + 1 < e){
        // check
        mid = (s+e)/2;
        long long temp = 0; // mid 시간 안에 심사 받을 수 있는 전체 사람 수
        for(int time: times)
            temp += mid / time;

        // 구간 좁히기
        if(temp >= n) // 가능하다면
            e = mid;
        else // 불가능하다면
            s = mid;
    }
    return e;
}
/*
    왜 굳이 시간을 배수로 두어야 하지?
    조건 분기가 많아진다면 혹시 불필요하게 조건을 제약하고 있는지 살펴보자
*/