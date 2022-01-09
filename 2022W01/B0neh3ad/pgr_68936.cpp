/*
    쿼드압축 후 개수 세기
    https://programmers.co.kr/learn/courses/30/lessons/68936
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);

    int size = arr.size();
    bool is_same = true;
    int val = arr[0][0];

    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            if(arr[i][j] != val){
                is_same = false;
                break;
            }
        }
    }

    if(is_same == true){
        answer[val] = 1;
    }
    else {
        for(int l=0; l<4; ++l){
            vector<vector<int>> arr_divided(size/2);
            for(int i=(size/2)*(l/2); i<size/2 + (size/2)*(l/2); ++i){
                for(int j=(size/2)*(l%2); j<size/2 + (size/2)*(l%2); ++j){
                    arr_divided[i-(size/2)*(l/2)].push_back(arr[i][j]);
                }
            }
            vector<int> temp = solution(arr_divided);
            answer[0] += temp[0];
            answer[1] += temp[1];
        }
    }

    return answer;
}

int main(void){
    vector<int> ans = solution({{1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1}});

     printf("%d %d", ans[0], ans[1]);
    return 0;
}
