/*
    좌표 압축
    https://www.acmicpc.net/problem/18870
*/

#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int N;
int coords[1000000];
map<int,int> m;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &coords[i]);
        m.insert({coords[i], 0});
    }
    int i=0;
    for(auto iter=m.begin();iter!=m.end();++iter) {
        m[(*iter).first] = i;
        ++i;
    }
    for(int i=0;i<N;i++) {
        printf("%d ", m[coords[i]]);
    }
}


// keyword: 좌표 압축, 정렬
// 시간복잡도: O(N log N)
/*
idea: map을 이용해 서로 다른 좌표를 모두 모음
그 뒤 map 내 key가 오름차순 정렬됨을 이용해 각 key에 대한 value 값을
압축 좌표로 설정
*/