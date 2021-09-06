/*
    괄호 회전하기
    https://programmers.co.kr/learn/courses/30/lessons/76502
*/
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    size_t str_size = s.size();
    if(str_size % 2){ return 0; }

    int answer = 0;
    map<char, int> br = {{'(', 0}, {')', 1}, {'[', 2}, {']', 3}, {'{', 4}, {'}', 5}};

    for(size_t x = 0; x < str_size; ++x){
        stack<char> st;
        // rotation
        int is_valid = 1;
        for(size_t i = x; i < x + str_size; ++i){
            // cout << "i: " << i << " ";
            int br_case = br[s[i % str_size]] / 2, op = br[s[i % str_size]] % 2; // val == 0 -> open, val == 1 -> close
            if(!op){ st.push(s[i % str_size]); }
            else{
                if(st.empty()){ is_valid = 0; break; }
                if(br_case != br[st.top()] / 2){ is_valid = 0; break; }
                st.pop();
            }
        }
        if(!st.empty()){ is_valid = 0; }
        // cout << endl;
        answer += is_valid;
    }
    return answer;
}

/*
    괄호짝 맞는 거 필요충분조건
    - 스택이 비어있는데 더 빼내려고 하면 안 됨
    - 스택에서 빼야하는데 top 원소랑 괄호짝 안 맞으면 안 됨
*/