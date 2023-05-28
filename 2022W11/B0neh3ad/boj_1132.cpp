#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using pii = pair<ull, bool>;

int n;

bool cmp(const pii& lhs, const pii& rhs){
    if(lhs.first == rhs.first){
        return lhs.second > rhs.second; 
    }
    else{
        return lhs.first > rhs.first;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    pii digit[10];
    for(int i=0; i<10; ++i){
        digit[i].first = 0; // 자릿값
        digit[i].second = true; // 0 가능 여부
    }

    for(int i=0; i<n; ++i){
        string inp;
        cin >> inp;
        ull val = 1;
        for(int idx=inp.size()-1; idx>=0; --idx, val *= 10){
            digit[inp[idx] - 'A'].first += val;
            if(idx == 0){
                digit[inp[idx] - 'A'].second = false;
            }
        }
    }

    sort(digit, digit+10, cmp);

    ull res = 0;
    int zero_idx = 9;
    while(zero_idx >= 0){
        if(digit[zero_idx].second){
            break;
        }
        --zero_idx;
    }

    ull val = 9;
    for(int i=0; i<10; ++i){
        if(i != zero_idx){
            res += val-- * digit[i].first;
        }
    }

    cout << res;

    return 0;
}