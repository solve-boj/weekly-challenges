#include <bits/stdc++.h>
using namespace std;

int force(int curr, int next){
    int ans;
    if(curr == 0){
        ans = 2;
    }
    else{
        switch((curr - next + 4) % 4){
            case 0:
            ans = 1;
            break; 

            case 1:
            case 3:
            ans = 3;
            break;

            case 2:
            ans = 4;
            break;
        }
    }
    return ans;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> seq;
    int inp;
    while(true){
        cin >> inp;
        if(!inp){ break; }
        seq.push_back(inp);
    }

    int n = seq.size();
    int dp[n][5][5];

    // init array
    for(int i=0; i<n; ++i){
        for(int l=0; l<5; ++l){
            for(int r=0; r<5; ++r){
                dp[i][l][r] = INT_MAX;
            }
        }
    }

    dp[0][0][seq[0]] = 2;
    for(int i=1; i<n; ++i){
        int next = seq[i];

        for(int l=0; l<5; ++l){
            for(int r=0; r<5; ++r){
                if(dp[i-1][l][r] < INT_MAX){
                    dp[i][next][r] = min(dp[i][next][r], dp[i-1][l][r] + force(l, next));
                    dp[i][l][next] = min(dp[i][l][next], dp[i-1][l][r] + force(r, next));
                }
            }
        }
    }

    int ans = INT_MAX;
    for(int l=0; l<5; ++l){
        for(int r=0; r<5; ++r){
            if(dp[n-1][l][r] < INT_MAX){
                ans = min(ans, dp[n-1][l][r]);
            }
        }
    }

    cout << ans;

    return 0;
}