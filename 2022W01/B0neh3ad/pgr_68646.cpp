/*
    풍선 터뜨리기
    https://programmers.co.kr/learn/courses/30/lessons/68646
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 3;
    int n = a.size();

    if(n <= 3){
        return n;
    }

    int min_idx = 0;
    int lhs_min_idx = 0, rhs_min_idx = n-1;

    for(int i=0; i<n; ++i){
        if(a[min_idx] > a[i]){
            min_idx = i;
        }
    }

    // lhs
    for(int i=0; i<min_idx; ++i){
        if(a[lhs_min_idx] > a[i]){
            lhs_min_idx = i;
        }
    }
    if(min_idx == lhs_min_idx){ --answer; }

    // rhs
    for(int i=min_idx+1; i<n; ++i){
        if(a[rhs_min_idx] > a[i]){
            rhs_min_idx = i;
        }   
    }
    if(min_idx == rhs_min_idx){ --answer; }

    // lhs
    int local_min = a[0];
    for(int i=0; i<lhs_min_idx; ++i){
        if(local_min >= a[i]){
            ++answer;
            local_min = a[i];
        }
    }

    // rhs
    local_min = a[n-1];
    for(int i=n-1; i>rhs_min_idx; --i){
        if(local_min >= a[i]){
            ++answer;
            local_min = a[i];
        }
    }

    return answer;
}

int main(void){
    printf("%d", solution({1,2,3,4,5}));
    return 0;
}