#include <bits/stdc++.h>
using namespace std;

int box[20];
int res;
bool error_flag;

void sol(int l, int w, int d){
    // cout << "sol(" << l << ", " << w << ", " << d << ")\n";
    if(error_flag || !l || !w || !d){ return; }

    int min_side = min({l, w, d});
    int len = 1, ex = 0;
    while(len <= min_side){
        len *= 2;
        ex += 1;
    }
    len /= 2;
    ex -= 1;
    while(box[ex] == 0){
        len /= 2;
        ex -= 1;
        if(ex < 0){
            error_flag = true;
            res = -1;
            return;
        }
    }
    // cout << "len: " << len << "\n";

    box[ex] -= 1;
    res += 1;

    sol(l-len, len, len);
    sol(l, w-len, len);
    sol(l, w, d-len);
}

int main(void){
    ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int l, w, d;
    cin >> l >> w >> d;

    int n;
    cin >> n;
    
    int kind;
    for(int i=0; i<n; ++i){
        cin >> kind >> box[i];
    }

    sol(l, w, d);

    cout << res;
    return 0;
}