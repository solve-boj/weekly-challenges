/*
    큰 수 만들기
    https://programmers.co.kr/learn/courses/30/lessons/42883
*/
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    while(idx<number.size()){
        int maxnum = -1;
        int maxidx = -1;
        for(int i=idx;i<idx+k+1 && i<number.size();i++){
            int num = number[i]-'0';
            if(num>maxnum){
                maxnum = num;
                maxidx = i;
            }
        }
        k-=maxidx-idx;
        answer+=number[maxidx];
        idx = maxidx+1;
    }
    return answer.substr(0, answer.size()-k);
}