#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int step[100001];
int cnt[100001];

int getNext(int curr, int op){
    switch(op){
        case 0:
        return curr+1;
        break;
        case 1:
        return curr-1;
        break;
        case 2:
        return 2*curr;
        break;
    }
}

pii bfs(int start, int end){
    if(start == end){ return pii(0, 1); }
    queue<int> q;

    step[start] = 0;
    cnt[start] = 1;

    q.push(start);

    int curr_step = step[start];
    while(!q.empty()){
        int qsize = q.size();
        ++curr_step;
        for(int i=0; i<qsize; ++i){
            int curr = q.front();
            q.pop();
            
            for(int k=0; k<3; ++k){
                int next = getNext(curr, k);
                if(next >= 0 && next <= 100000){
                    if(!cnt[next]){
                        step[next] = curr_step;
                        cnt[next] += cnt[curr];
                        q.push(next);
                    }
                    else if(step[next] == curr_step){
                        cnt[next] += cnt[curr];
                    }
                }
            }
        }
        if(cnt[end]){
            return pii(curr_step, cnt[end]);
        }
    }
    return pii(-1, -1);
}

int main(void){
    int n, k;
    cin >> n >> k;

    pii ans = bfs(n, k);
    cout << ans.first << "\n" << ans.second;
    return 0;
}