#include <bits/stdc++.h>
using namespace std;

int main(void){
    int k, w, m;
    cin >> k >> w >> m;

    if(k >= w){
        cout << 0;
    }
    else {
        int res = (w-k) / m;
        if((w-k) % m){ ++res; }
        cout << res;
    }
    return 0;
}