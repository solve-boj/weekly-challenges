/*
    124 나라의 숫자
    https://programmers.co.kr/learn/courses/30/lessons/12899
*/
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    static string table[4] = {
        "",
        "1",
        "2",
        "4"
    };

    if(n <= 3)
        return table[n];
    else if(n % 3 == 0)
        return solution(n/3-1) + solution(3);
    else
        return solution(n/3) + solution(n%3);
}