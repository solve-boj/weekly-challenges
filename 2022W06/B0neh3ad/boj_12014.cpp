#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int x=1; x<=t; ++x){
        int n, k;
        cin >> n >> k;

        int arr[n];
        for(int i=0; i<n; ++i){
            cin >> arr[i];
        }

        vector<int> res;
        res.push_back(arr[0]);
        for(int i=1; i<n; ++i){
            if(res.back() < arr[i]){
                res.push_back(arr[i]);
            } else {
                res[lower_bound(res.begin(), res.end(), arr[i]) - res.begin()] = arr[i];
            }
        }

        cout << "Case #"<<x<<"\n";
        cout << (k <= res.size()) << "\n";
    }
    return 0;
}