/*
    약수의 개수와 덧셈
    https://programmers.co.kr/learn/courses/30/lessons/77884
*/
#include <algorithm>

using namespace std;

long long solution(int price, int money, int count)
{
    auto result = count*(count+1ll)/2*price - money;
    return max(0ll, result);
}