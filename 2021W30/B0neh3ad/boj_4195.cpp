#include <cstdio>
#include <unordered_map>
#include <string>
#include <algorithm>

const int MAX_SIZE = 200000;

int p[MAX_SIZE];

int find(int n){
    if(p[n] < 0){ return n; }
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){ return; }
    p[a] += p[b]; // 친구 수 더하기
    p[b] = a;
}

int main(void){
    int t;
    scanf("%d", &t);

    for(int h=0; h<t; ++h){
        std::fill(p, p+MAX_SIZE, -1);

        int f;
        scanf("%d", &f);

        std::unordered_map<std::string, int> people;
        char p1[21], p2[21];
        int cnt = 0;
        for(int i=0; i<f; ++i){
            scanf("%s %s", p1, p2);
            // 사람 넘버링
            people.insert({p1, people.size()});
            people.insert({p2, people.size()});
            // 관계 형성
            merge(people[p1], people[p2]);
            // 친구 수 출력
            printf("%d\n", -p[find(people[p1])]);
        }
    }
    return 0;
}

/*
    map 사용법에 대한 공부 필요
    string을 scanf로 입력받는 경우에는 이후 변수 활용 과정에서 문제가 생긴다.
    그 이유는 정확히 모르겠다.
    다만 그 대안으로는 아래의 몇 가지가 있다.
    1) char []에 입력 받고 넘기기
    2) ...
*/