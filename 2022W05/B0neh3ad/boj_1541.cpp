#include <bits/stdc++.h>
using namespace std;

int main(void){
    string inp;
    cin >> inp;

    int n = inp.size();
    int s = 0, len = 0;

    vector<int> nums;
    vector<int> ops;
    for(int i=0; i<n; ++i, ++len){
        if(i == n-1 || inp[i] == '+' || inp[i] == '-'){
            if(i == n-1){ ++len; }
            nums.push_back(stoi(inp.substr(s, len)));
            s = i+1;
            len = -1;
            switch(inp[i]){
                case '+':
                ops.push_back(1);
                break;

                case '-':
                ops.push_back(-1);
                break;
            }
        }
    }

    int ans = nums[0];
    bool flag = false;
    for(int i=0; i<ops.size(); ++i){
        if(ops[i] == -1){
            flag = true;
        }
        else{
            if(flag){
                ops[i] = -1;
            }
        }

        switch(ops[i]){
            case 1:
            ans += nums[i+1];
            break;

            case -1:
            ans -= nums[i+1];
            break;
        }
    }

    cout << ans;

    return 0;
}