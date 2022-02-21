#include <bits/stdc++.h>
using namespace std;

int n, k;
bool dp[1 << 24];
int finish;

int sol(int start){
    if(start == finish){ return 0; }
    queue<int> q;
    q.push(start);
    dp[start] = true;

    int step = 1;
    while(!q.empty()){
        int qsize = q.size();
        for(int x=0; x<qsize; ++x){
            int curr = q.front();
            q.pop();
            for(int i=0; i<=n-k; ++i){
                int next = curr;
                int s=i, e=i+k-1;
                while(s<e){
                    int temp = (next & 7 << (s*3)) >> (s*3);
                    next &= ~(7 << (s*3));
                    next |= (next & 7 << (e*3)) >> ((e-s)*3);
                    next &= ~(7 << (e*3));
                    next |= temp << (e*3);
                    ++s; --e;
                }
                
                if(!dp[next]){
                    q.push(next);
                    dp[next] = true;
                    if(next == finish){
                        return step;
                    }
                }
            }
        }
        ++step;
    }

    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    int inp[n], start = 0;
    for(int i=0; i<n; ++i){
        cin >> inp[i];
        start <<= 3;
        start += inp[i]-1;
    }

    for(int i=0; i<n; ++i){
        finish <<= 3;
        finish += i;
    }

    cout << sol(start);
    return 0;
}