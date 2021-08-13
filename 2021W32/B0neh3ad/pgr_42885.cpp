#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    vector<bool> visited(people.size(), false);
    int answer = 0;

    int s = 0, e = people.size() - 1;
    while(s < e){
        if(people[s] + people[e] <= limit){
            visited[s] = true;
            ++s;
        }
        visited[e] = true;
        --e;
        ++answer;
    }
    
    if(!visited[s]){ ++answer; } // 여기 !people[s]로 했었음 ㅋㅋ

    return answer;
}

int main(){
    cout << solution(vector<int>({10, 10, 10, 10, 10}), 50);
    return 0;
}
/*
    1트: 답은 다 맞았으나 효율성에서 실패. O(n^2)은 너무 큰 듯.
    음... 이거 걍 two pointer 아니냐? 그러면 (정렬 포함) O(nlogn) 가능할 듯
    2트: two pointer로 패스.
*/