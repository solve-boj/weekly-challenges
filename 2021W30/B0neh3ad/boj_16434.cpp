/*
    드래곤 앤 던전
    https://www.acmicpc.net/problem/16434
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long H_atk;
    cin >> N >> H_atk;

    long long info[N][3];
    for(int i=0; i<N; ++i){
        for(int j=0; j<3; ++j)
            cin >> info[i][j];
    }

    long long s = 0, e = 1000000000000000000;
    long long mid;
    while(s+1 < e){
        int flag = 1;
        long long mid = (s+e) / 2;
        long long curr_hp = mid, curr_atk = H_atk;
        for(int i=0; i<N; ++i){
            switch(info[i][0]){
            case 1:
                if(info[i][2] / curr_atk + ((info[i][2] % curr_atk) ? 1 : 0) <= curr_hp / info[i][1] + ((curr_hp % info[i][1]) ? 1 : 0)){ // 생존하는 경우
                    curr_hp -= info[i][1] * ((info[i][2] / curr_atk) + ((info[i][2] % curr_atk) ? 0 : -1)); // 몬스터 때린 횟수만큼 맞았으니까 그만큼 까기
                    if(curr_hp <= 0) { flag = 0; break; } // 사망하는 경우
                }
                else{ flag = 0; break; } // 사망하는 경우
                break;

            case 2:
                curr_atk += info[i][1]; // 공격력 증가
                curr_hp = min(curr_hp+info[i][2], mid); // hp 증가
                break;
            }
        }
        if(flag){ e = mid; }
        else{ s = mid; }
    }

    cout << e;
    return 0;
}
/*
    unsigned 쓰기 전에는
    '정말 부호 변화가 절대 일어나지 않는가?'
    를 고려하자

    입력값은 되도록이면 r-value로만!
    l-value로 쓰기 전엔 항상 고민하자
*/