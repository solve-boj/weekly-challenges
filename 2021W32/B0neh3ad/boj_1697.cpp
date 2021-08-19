/*
    숨바꼭질
    https://www.acmicpc.net/problem/1697
*/
#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int loc[100001] = {0, };
    queue<int> q;

    loc[n] = -1;
    q.push(n);

    int qsize, time = 0;
    bool flag = false;
    while(!q.empty()){
        qsize = q.size();
        ++time;
        for(int i=0; i<qsize; ++i){
            int curr = q.front();
            q.pop();
            
            if(curr+1 >= 0 && curr+1 <= 100000 && !loc[curr+1]){
                loc[curr+1] = time;
                if(curr+1 == k){ flag = true; break; }
                q.push(curr+1);
            }
            if(curr-1 >= 0 && curr-1 <= 100000 && !loc[curr-1]){
                loc[curr-1] = time;
                if(curr-1 == k){ flag = true; break; }
                q.push(curr-1);
            }
            if(2*curr >= 0 && 2*curr <= 100000 && !loc[2*curr]){
                loc[2*curr] = time;
                if(2*curr == k){ flag = true; break; }
                q.push(2*curr);
            }
        }
        if(flag){ break; }
    }
    
    loc[n] = 0; // 이거 깜빡하고 안 해줘서 2트함
    cout << loc[k];
    return 0;
}
/*
    기본은 dp
    그런데 이제 bfs를 곁들인..

    29679729 <- 완전히 dp만 이용한 풀이
    case를 나누면 최적해를 찾는 방법이 한정된다.
*/