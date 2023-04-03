#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 8;

int n;
int x[MAX_N], ch[MAX_N];
vector<int> s;

bool check(){
    int idx[n][2];
    memset(idx, -1, sizeof(idx));
    for(int i=0; i<n*2; ++i){
        for(int j=0; j<n; ++j){
            if(s[i] == x[j]){
                idx[j][idx[j][0] != -1] = i;
            }
        }
    }

    for(int i=0; i<n; ++i){
        int dist = idx[i][1] - idx[i][0];
        if(x[i] != dist-1)
            return false;
    }

    for(int i=0; i<n*2; ++i){
        cout << s[i] << " ";
    }
    return true;
}

bool solve(){
    if(s.size() == n*2){
        return check();
    }

    bool ret = false;
    for(int i=0; i<n; ++i){
        if(ch[i] == -1){
            ch[i] = s.size();
            s.push_back(x[i]);
            ret = ret || solve();
            ch[i] = -1;
            s.pop_back();
        }
        else if(ch[i] < MAX_N*2){
            if(s.size() - ch[i] - 1 != x[i])
                continue;
            int tmp = ch[i];

            ch[i] = MAX_N*2;
            s.push_back(x[i]);
            ret = ret || solve();
            ch[i] = tmp;
            s.pop_back();
        }
    }
    return ret;
}

int main(void){
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> x[i];
    sort(x, x+n);
    memset(ch, -1, sizeof(ch));

    if(!solve()){
        cout << -1;
    }
    
    return 0;
}