/*
    멀쩡한 사각형
    https://programmers.co.kr/learn/courses/30/lessons/62048
*/
#include <iostream>

using namespace std;

long long solution(int w,int h) {
    int temp;
    if(w > h){
        temp = w;
        w = h;
        h = temp;
    }

    long long new_w = w, new_h = h;
    long long answer = h;
    for(int i=1; i<=new_w; ++i){
        answer += ((new_h%new_w)*(i%new_w)%new_w) ? 1 : 0;
    }

    answer = new_w*new_h - answer;
    return answer;
}

int main(void){
    cout << solution(8, 12);
    return 0;
}

/*
    첫 시도: 그냥 ceil(기울기) * min(w, h) 해버림
    -> 기울기가 같아도 각 지점에서 칸 수가 달라지는 경우가 있음(ex) solution(8, 13))

    두 번째 시도: 각 지점 별 s, e 값 구해서 answer = w*h - sum(e-s)식으로 구함
    이때 s, e값이란 각 column의 왼쪽, 오른쪽 지점에서 대각선이 지나는 y좌표? 정도.
    예를 들어 solution(2, 7)의 경우 i=0일 때 s=0, e=3.5, i=1일 때 s=3.5, e=7
    근데 w, h의 범위가 1억 이하이다 보니 s, e값이 너무 커져버림.

    세 번째 시도: 결국 각 교차점의 y좌표가 정수인지 여부에 따라서만 결정되는 것.
    이를 바탕으로 위 코드 구현.
    -> 성공! 시간복잡도는 O(n)
*/