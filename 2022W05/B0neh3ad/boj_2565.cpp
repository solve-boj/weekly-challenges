#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n;
pii ties[100];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> ties[i].first >> ties[i].second;
    }
    sort(ties, ties+n);

    vector<int> res;
    res.push_back(ties[0].second);
    for(int i=1; i<n; ++i){
        if(res.back() < ties[i].second){
            res.push_back(ties[i].second);
        }
        else {
            res[lower_bound(res.begin(), res.end(), ties[i].second) - res.begin()] = ties[i].second;
        }
    }

    cout << n-res.size();    

    return 0;
}