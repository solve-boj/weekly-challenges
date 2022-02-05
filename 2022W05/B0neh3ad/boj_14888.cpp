#include <bits/stdc++.h>
using namespace std;
#define MAX_VAL 1000000000

int n;
int nums[11];

int max_res = -MAX_VAL, min_res = MAX_VAL;

void sol(vector<int> ops, int cnt, int res){
    // cout << "sol({" << ops[0] << ", " << ops[1] << ", " << ops[2] << ", " << ops[3] << "}, " << cnt << ", " << res << ")\n";
    if(cnt == n-1){
        max_res = max(max_res, res);
        min_res = min(min_res, res);
        return;
    }

    for(int i=0; i<4; ++i){
        if(ops[i]){
            ops[i] -= 1;
            switch(i){
                case 0:
                sol(ops, cnt+1, res + nums[cnt+1]);
                break;
                case 1:
                sol(ops, cnt+1, res - nums[cnt+1]);
                break;
                case 2:
                sol(ops, cnt+1, res * nums[cnt+1]);
                break;
                case 3:
                sol(ops, cnt+1, res / nums[cnt+1]);
                break;
            }
            ops[i] += 1;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> nums[i];
    }

    vector<int> ops(4);
    for(int i=0; i<4; ++i){
        cin >> ops[i];
    }

    sol(ops, 0, nums[0]);

    cout << max_res << "\n" << min_res;
    return 0;
}