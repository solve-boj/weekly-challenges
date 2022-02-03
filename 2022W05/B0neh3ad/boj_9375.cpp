#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        map<string, int> kinds;
        while(n--){
            string name, kind;
            cin >> name >> kind;
            if(kinds.find(kind) == kinds.end()){
                kinds.insert({kind, 1});
            } else {
                ++kinds[kind];
            }
        }

        int ans = 1;
        for(auto elem: kinds){
            ans *= (elem.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }
    return 0;
}