#include <bits/stdc++.h>
using namespace std;

int l, c;
char ch[15];
char ans[16], vow[5] = {'a', 'e', 'i', 'o', 'u'};

// cnt: 현재 문자열 길이, pos: 현재 문자 위치
// con_cnt: 자음, vow_cnt: 모음
void solution(int cnt, int pos, int con_cnt, int vow_cnt){
    // 문자열 길이가 l이 된 경우
    if(cnt == l){
        // 조건 만족 시 출력
        if(con_cnt >= 2 && vow_cnt >= 1){
            ans[cnt+1] = '\0';
            cout << ans << endl;
        }
        return;
    }
    // 문자 다 안 썼는데 끝까지 도달함
    if(pos == c-1){ return; }

    ans[cnt] = ch[pos+1];
    bool is_vow = false;
    for(int i=0; i<5; ++i){
        if(vow[i] == ch[pos+1]){
            is_vow = true;
        }
    }

    if(is_vow){
        solution(cnt+1, pos+1, con_cnt, vow_cnt+1);
    } else {
        solution(cnt+1, pos+1, con_cnt+1, vow_cnt);
    }

    solution(cnt, pos+1, con_cnt, vow_cnt);
}

int main(void){
    cin >> l >> c;
    for(int i=0; i<c; ++i){
        cin >> ch[i];
    }

    sort(ch, ch+c);

    solution(0, -1, 0, 0);

    return 0;
}