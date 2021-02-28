/*
    예상 대진표
    https://programmers.co.kr/learn/courses/30/lessons/12985
*/
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = log2(n);
    int start = 1;
    int end = n;
    while(start!=end){
        int middle = (start+end)/2;
        //check left
        if(a<=middle && b<=middle){
            end = middle;
            answer--;
        }
        else if(a>middle && b>middle){
            start = middle;
            answer--;
        }
        else {
            break;
        }
    }
    return answer;
}