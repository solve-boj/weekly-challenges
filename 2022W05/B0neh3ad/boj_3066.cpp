#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

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

        cout << res.size() << "\n";
    }
    
    return 0;
}