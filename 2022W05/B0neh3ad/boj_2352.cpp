#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ports[n];
    for(int i=0; i<n; ++i){
        cin >> ports[i];
    }

    vector<int> res;
    res.push_back(ports[0]);
    for(int i=1; i<n; ++i){
        if(res.back() < ports[i]){
            res.push_back(ports[i]);
        }
        else {
            res[lower_bound(res.begin(), res.end(), ports[i]) - res.begin()] = ports[i];
        }
    }

    cout << res.size();
    return 0;
}