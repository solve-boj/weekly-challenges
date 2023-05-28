#include <bits/stdc++.h>
using namespace std;

int l, n;
string inp[20];
vector<int> res_idx;

bool sol(int idx, int cnt, vector<int> prevs){
    if(!res_idx.empty()){
        return true;
    }
    
    for(int i=0; i<prevs.size(); ++i){
        if(inp[idx][i] != inp[prevs[i]][cnt]){
            return false;
        }
    }

    prevs.push_back(idx);
    if(cnt == l-1){
        res_idx = prevs;
        return true;
    }

    bool res = false;
    for(int i=0; i<n; ++i){
        if(!count(prevs.begin(), prevs.end(), i)){
            res |= sol(i, cnt+1, prevs);
        }
    }

    return res;
}

int main(void){
    cin >> l >> n;

    for(int i=0; i<n; ++i){
        cin >> inp[i];
    }

    sort(inp, inp+n);
    bool res = false;
    for(int i=0; i<n; ++i){
        res |= sol(i, 0, {});
    }

    if(!res){
        cout << "NONE";
    }
    else {
        for(int idx: res_idx){
            cout << inp[idx] << "\n";
        }
    }
    
    return 0;
}