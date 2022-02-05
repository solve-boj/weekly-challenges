#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    int min_div = 1000001, max_div = 1;
    int div;
    for(int i=0; i<n; ++i){
        cin >> div;
        min_div = min(min_div, div);
        max_div = max(max_div, div);
    }

    cout << min_div*max_div;
    return 0;
}