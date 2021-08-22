/*
    스타 수열
    https://programmers.co.kr/learn/courses/30/lessons/70130
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(std::vector<int> a) {
    int answer = -1;
    vector<int> res(a.size());
    vector<int> last_idx(a.size());
    vector<bool> last_loc(a.size()); // true: {n, _} false: {_, n}

    fill(res.begin(), res.end(), 0);
    fill(last_idx.begin(), last_idx.end(), -1);
    fill(last_loc.begin(), last_loc.end(), false);

    for(int i=0; i<a.size(); ++i){
        int delta = i - last_idx[a[i]];
        if(delta == 1){
            if(!last_loc[a[i]]){
                last_loc[a[i]] = true;
                res[a[i]] += 1;
            }
        }
        else if(last_loc[a[i]] && delta >= 3){
            last_loc[a[i]] = false;
            res[a[i]] += 3;
        }
        else{
            res[a[i]] += 2;
        }
        last_idx[a[i]] = i;
    }

    for(int i=0; i<a.size(); ++i){
        if(last_loc[a[i]] && last_idx[a[i]] < a.size() - 1){
            res[a[i]] += 1;
            last_idx[a[i]] = a.size() - 1;
        }
        res[a[i]] = res[a[i]] / 2 * 2;
        answer = max(answer, res[a[i]]);
    }
    return answer;
}
/*
    별 생각을 다했는데...
    결국 기본 아이디어는
    이웃한 경우 / 1칸 띈 경우 / 2칸 이상 띈 경우
    에 따라서 해야할 일이 달라진다는 게 포인트.
    거기에 last_loc 배열로 직전 부분 집합 내에서 원소의 위치를 기록한 뒤
    이걸로도 조건 분기.
    코드 상으로는 3~4개지만 사실상 3X2 = 6개로 분기한 셈.

    근데 정답 코드들은 ㄹㅇ 간단한 거 같기도 하고... 아 모르겠다 풀었으니까 됐지 뭐
*/