#include <bits/stdc++.h>
using namespace std;
#define MAX_N 4000000

bool prime[MAX_N + 1];

void set_prime(){
    for(int i=2; i*i<=MAX_N; ++i){
        for(int j=i*2; j<=MAX_N; j+=i){
            prime[j] = false;
        }
    }
}

int main(void){
    int n;
    cin >> n;

    fill(prime, prime+MAX_N+1, true);
    set_prime();

    int ans = 0;
    int s = 2, e = 2, limit = n;
    int psum = 2;
    while(!prime[limit]){
        --limit;
    }
    while(s <= limit && e <= limit){
        if(psum <= n){
            if(psum == n){ ++ans; }
            while(!prime[++e]){
                if(e == limit){ break; }
            }
            psum += e;
        }
        else {
            psum -= s;
            while(!prime[++s]){
                if(s == limit){ break; }
            }
        }
    }

    cout << ans;
    return 0;
}