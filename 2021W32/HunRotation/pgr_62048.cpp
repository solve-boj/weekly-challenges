/*
    멀쩡한 사각형
    https://programmers.co.kr/learn/courses/30/lessons/62048
*/
#include <numeric>

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    answer = (long long)w*h - w - h + gcd(w, h);
    return answer;
}