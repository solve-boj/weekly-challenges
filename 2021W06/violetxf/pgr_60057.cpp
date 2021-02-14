/*
    문자열 압축
    https://programmers.co.kr/learn/courses/30/lessons/1830
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int digits(int num){
    return log10(num)+1;
}
int solution(string s) {
    int length = s.size();
    int answer = length;
    for(int i=1;i<=length/2;i++){
        int zippedLength = length;
        int dupl = 0;
        int cursor = 0;
        string prev="";
        while(cursor+i<=length){
            int start = cursor;
            int count = i;
            string sub = s.substr(start, count);
            if(sub==prev){
                dupl++;
            } else {
                if(dupl>=1){
                    zippedLength -= i*dupl-digits(dupl+1);
                }
                dupl = 0;
            }
            prev = sub;
            cursor+=i;
        }
        if(dupl>=1){
                zippedLength -= i*dupl-digits(dupl+1);
        }
        answer = min(answer, zippedLength);
    }
    return answer;
}