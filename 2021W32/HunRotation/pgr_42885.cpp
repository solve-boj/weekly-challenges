/*
    구명보트
    https://programmers.co.kr/learn/courses/30/lessons/42885
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = people.size();
    sort(people.begin(), people.end());
    int l=0, r=people.size()-1;
    while(l<r) {
        if(people[l] + people[r] > limit) {
            r--;
        }
        else {
            answer--;
            l++;
            r--;
        }
    }

    return answer;
}

// keyword: 정렬, 그리디 알고리즘
// 시간복잡도: O(N)
/*
idea: 사람들 몸무게를 작은 순서대로 정렬한 후, 몸무게 작은 사람부터 확인
그 사람과 같이 탈 수 있는 무게의 사람을 큰 쪽부터 차례로 찾음
한 쌍이 만들어질 때마다 필요한 횟수 1씩 감소
*/