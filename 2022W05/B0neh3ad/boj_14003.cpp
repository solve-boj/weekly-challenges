#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool cmp(const pii& lhs, const pii& rhs){ return lhs.first < rhs.first; }

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int seq[n];
    for(int i=0; i<n; ++i){
        cin >> seq[i];
    }

    vector<pii> res;
    int prev[n];

    res.push_back({seq[0], 0});
    prev[0] = -1;

    for(int i=1; i<n; ++i){
        pii curr = {seq[i], i};
        if(res.back().first < seq[i]){
            prev[i] = res.back().second;
            res.push_back(curr);
        }
        else{
            int idx = lower_bound(res.begin(), res.end(), curr, cmp) - res.begin();
            prev[i] = idx ? res[idx-1].second : -1;
            res[idx] = curr;
        }
    }

    bool include[n] = {0, };
    for(int i=res.back().second; i>=0; i=prev[i]){
        include[i] = true;
    }
    
    cout << res.size() << "\n";
    for(int i=0; i<n; ++i){
        if(include[i]){
            cout << seq[i] << " ";
        }
    }
    return 0;
}