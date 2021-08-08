/*
    전화번호 목록
    https://programmers.co.kr/learn/courses/30/lessons/42577
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++) {
        if (phone_book[i+1].substr(0, phone_book[i].size()) == phone_book[i]) {
            answer = false;   
        }
    }
    
    return answer;
}


// keyword: 정렬
// 시간복잡도: O(N log N))
/*
idea: string을 순서대로 정렬하면, 앞쪽 파트가 똑같을 때 길이가 더 긴 것이
더 짧은 것 바로 뒤에 온다는 점을 이용
*/