#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
        a[i] = 10000 - a[i];
    }

    vector<int> res;
    res.push_back(a[0]);
    for(int i=1; i<n; ++i){
        if(res.back() < a[i]){
            res.push_back(a[i]);
        }
        else{
            res[lower_bound(res.begin(), res.end(), a[i]) - res.begin()] = a[i];
        }
    }

    cout << res.size();
    return 0;
}