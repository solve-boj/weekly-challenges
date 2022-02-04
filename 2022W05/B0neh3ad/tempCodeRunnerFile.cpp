#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    pii lines[n];
    for(int i=0; i<n; ++i){
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines, lines+n);

    /*
    cout << "-- sorted --\n";
    for(int i=0; i<n; ++i){
        cout << lines[i].first << " " << lines[i].second << "\n";
    }
    */

    // cout << "-- stack --\n";
    vector<pii> st, ans;
    bool exclude[n] = {0, };
    st.push_back({lines[0].second, 0});
    for(int i=1; i<n; ++i){
        pii curr = {lines[i].second, i};
        if(st.back().first < curr.first){
            st.push_back(curr);
        }
        else{
            int idx = lower_bound(st.begin(), st.end(), curr) - st.begin();
            if(idx+1 == st.size()){ st[idx] = curr; }
        }
        if(ans.size() < st.size()){
            ans = st;
        }
        for(auto it: st){
            cout << it.second << ' ';
        }
        cout << '\n';
    }

    for(auto it: ans){
        exclude[it.second] = true;
    }

    // cout << "-- ans -- \n";
    cout << n-ans.size() << '\n';
    for(int i=0; i<n; ++i){
        if(!exclude[i]){
            cout << lines[i].first << '\n';
        }
    }
    return 0;
}