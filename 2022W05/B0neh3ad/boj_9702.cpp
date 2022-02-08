#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int x=1; x<=t; ++x){
        int n;
        cin >> n;

        int arr[n];
        for(int i=0; i<n; ++i){
            cin >> arr[i];
        }
        
        int ans = n;
        for(int s=0; s<n; ++s){
            vector<int> res;
            res.push_back(arr[s]);
            for(int i=s+1; i<n; ++i){
                if(res.back() < arr[i]){
                    res.push_back(arr[i]);
                } else {
                    res[lower_bound(res.begin(), res.end(), arr[i]) - res.begin()] = arr[i];
                }
                ans += res.size();
            }
        }

        cout << "Case #"<<x<<": "<<ans<<"\n";
    }
    return 0;
}