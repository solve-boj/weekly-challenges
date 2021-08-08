/*
    오름세
    https://www.acmicpc.net/problem/3745
*/
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

int main(void){
    while(true){
        int N;
        if(scanf("%d", &N) == EOF){ break; }

        int temp;
        std::vector<int> res;

        scanf("%d", &temp);
        res.push_back(temp);

        for(int i=1; i<N; ++i){
            scanf("%d", &temp);
            if(res.back() < temp){ res.push_back(temp); }
            else{ res[std::lower_bound(res.begin(), res.end(), temp) - res.begin()] = temp; }
        }
        printf("%d\n", res.size());
    }
    return 0;
}