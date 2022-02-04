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

    vector<pii> st;
    bool exclude[n] = {0, };
    int prev[n]; // 이 문제 풀이의 핵심
    
    st.push_back({lines[0].second, 0});
    prev[0] = -1;

    for(int i=1; i<n; ++i){
        pii curr = {lines[i].second, i};
        if(st.back().first < curr.first){
            prev[i] = st.back().second;
            st.push_back(curr);
        }
        else{
            int idx = lower_bound(st.begin(), st.end(), curr) - st.begin();
            if(idx == 0){
                prev[i] = -1;
            }
            else {
                prev[i] = st[idx-1].second;
            }
            st[idx] = curr;
        }
    }

    cout << n-st.size() << '\n';

    for(int i=st.back().second; i>=0; i=prev[i]){
        exclude[i] = true;
    }
    for(int i=0; i<n; ++i){
        if(!exclude[i]){
            cout << lines[i].first << '\n';
        }
    }
    return 0;
}

// 정석적으로 풀도록 하자..