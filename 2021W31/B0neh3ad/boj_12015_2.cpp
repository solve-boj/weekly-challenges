/*
    가장 긴 증가하는 부분 수열 2
    https://www.acmicpc.net/problem/12015
*/
#include <cstdio>
#include <vector>
#include <algorithm>

int main(void){
    int N;
    scanf("%d", &N);

    int temp;
    std::vector<int> res;

    scanf("%d", &temp);
    res.push_back(temp);

    for(int i=1; i<N; ++i){
        scanf("%d", &temp);
        if(res.back() < temp){ res.push_back(temp); }
        else{ res[std::lower_bound(res.begin(), res.end(), temp) - res.begin()] = temp; }
    }
    printf("%d", res.size());
    return 0;
}