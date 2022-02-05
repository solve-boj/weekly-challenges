/*
    외벽 점검
    https://programmers.co.kr/learn/courses/30/lessons/60062
*/

#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1;
    int len = weak.size();

    // 마지막 원소와 첫 원소 사이 거리
    int max_int = weak.front() - weak.back() + n;
    // interval 저장 배열
    int int_arr_temp[len], max_int_idx = 0;
    
    // find max interval and its index
    int_arr_temp[0] = max_int;
    for(int i=1; i<len; ++i){
        int_arr_temp[i] = weak[i] - weak[i-1];
        if(max_int < int_arr_temp[i]){
            max_int_idx = i;
            max_int = int_arr_temp[i];
        }
    }

    // define interval array without max interval
    int int_arr[len-1], i=0;

    // slicing
    for(int temp_i=max_int_idx+1; temp_i<len; ++temp_i, ++i){
        int_arr[i] = int_arr_temp[temp_i];
    }
    for(int temp_i=0; temp_i<=max_int_idx-1; ++temp_i, ++i){
        int_arr[i] = int_arr_temp[temp_i];
    }

    /* logging */
    // for(int i=0; i<len-1; ++i){ printf("%d ", int_arr[i]); }

    // find max dist
    sort(dist.begin(), dist.end());
    int max_dist = dist.back();

    int int_sum = 0;
    for(int i=0; i<len-1; ++i){
        if(int_sum + int_arr[i] <= max_dist){ // 아직 안 쓴 dist 중 최댓값으로 모두 커버가 되는 경우
            int_sum += int_arr[i];
        }
        else{ // 하나의 dist로 더 커버가 안 되는 경우
            // 커버 가능한 dist 범위 내에서 가장 작은 dist로 커버
            for(vector<int>::iterator it = dist.begin(); it != dist.end(); ++it){
                if(*it >= int_sum){
                    dist.erase(it);
                    break;
                }
            }
            max_dist = dist.back();
            // 바로 다음 weak 지점에서 시작
            ++answer;
            int_sum = 0;
        }
        if(dist.empty() && i<n-2){ // 친구들 모두 투입했는데 다 처리 안 됨
            answer = -1;
            break;
        }
    }

    return answer;
}

int main(void){

    printf("%d", solution(200, {0,100}, {1,1,1,1,1,1,1,1}));
    return 0;
}