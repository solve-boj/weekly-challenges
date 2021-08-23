/*
    무지의 먹방 라이브
    https://programmers.co.kr/learn/courses/30/lessons/42891
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<long long, int >& lhs, pair<long long, int >& rhs){ return lhs.second < rhs.second; }

int solution(vector<int> food_times, long long k) {
    int answer = 0;

    // 1. 데이터 가공(<시간, {그때 다 먹는 음식들의 인덱스}> pair array 만들고 정렬)
    vector<pair<long long, int> > temp_list;
    for(int i=0; i<food_times.size(); ++i)
        temp_list.push_back({food_times[i], i+1});
    sort(temp_list.begin(), temp_list.end());

    // 2. k초 후 다 먹은 음식 개수 및 앞으로 먹을 음식이 남은 것 중 앞에서 몇 번째인지 계산
    int n = temp_list.size();
    int idx = 0;
    int remain;
    for(; idx < n; ++idx){
        long long diff = idx == 0 ? temp_list[idx].first : temp_list[idx].first - temp_list[idx-1].first;
        if(k < diff * (n-idx)){ remain = k % (n-idx); break; }
        k -= diff * (n-idx);
    }

    if(idx == n){ return -1; }

    // 3. 앞으로 먹을 음식의 위치 계산 -> 부분 정렬 후 인덱싱
    sort(temp_list.begin()+idx, temp_list.end(), cmp);
    answer = temp_list[idx + remain].second;

    return answer;
}
/*
    드럽게 복잡하네...
*/