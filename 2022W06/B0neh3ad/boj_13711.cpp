#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n], b[n];
    int idx[n+1], seq[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
        idx[a[i]] = i;
    }
    for(int i=0; i<n; ++i){
        cin >> b[i];
        seq[i] = idx[b[i]];
    }

    vector<int> res;
    res.push_back(seq[0]);
    for(int i=1; i<n; ++i){
        if(res.back() < seq[i]){
            res.push_back(seq[i]);
        }
        else{
            res[lower_bound(res.begin(), res.end(), seq[i]) - res.begin()] = seq[i];
        }
    }

    cout << res.size();

    return 0;
}