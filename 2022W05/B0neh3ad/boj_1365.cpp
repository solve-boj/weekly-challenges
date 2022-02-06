#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int inp[n];
    for(int i=0; i<n; ++i){
        cin >> inp[i];
    }

    vector<int> res;
    res.push_back(inp[0]);
    for(int i=1; i<n; ++i){
        if(res.back() < inp[i]){
            res.push_back(inp[i]);
        }
        else{
            res[lower_bound(res.begin(), res.end(), inp[i]) - res.begin()] = inp[i];
        }
    }

    cout << n - res.size();

    return 0;
}