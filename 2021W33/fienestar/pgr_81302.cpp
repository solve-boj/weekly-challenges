/*
    거리두기 확인하기
    https://programmers.co.kr/learn/courses/30/lessons/81302
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
"POOOP",
"OXXOX", 
"OPXPX",
"OOXOX",
"POXXP"
*/

bool is_valid_place(const vector<string>& place)
{
    constexpr size_t N = 5;
    
    vector<vector<int>> is_in_use(
        N,
        vector<int>(N, false)
    );
    
    int di[] = {1,-1,0,0};
    int dj[] = {0,0,1,-1};

    for(size_t i=0; i!=N; ++i)
        for(size_t j=0; j!=N; ++j)
            if(place[i][j] == 'P'){
                for(size_t k=0; k!=4; ++k){
                    size_t moved_i = i + di[k];
                    size_t moved_j = j + dj[k];
                    
                    if(moved_i >= N || moved_j >= N)
                        continue;
                    
                    switch(place[moved_i][moved_j]){
                        case 'P':
                            return false;
                        case 'O':
                            if(is_in_use[moved_i][moved_j])
                                return false;
                            
                            is_in_use[moved_i][moved_j] = true;
                            break;
                        case 'X':
                            break;
                    }
                }
            }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);
    for(size_t i=0; i!=5; ++i)
        answer[i] = is_valid_place(places[i]);
    return answer;
}