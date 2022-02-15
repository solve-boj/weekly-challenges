#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, t;
    cin >> a >> t;

    int s = 0, e = t.size()-1;
    int an = a.size();
    bool flag = false;
    while(true){
        flag = false;
        for(int i=s; i<t.size(); ++i){
            if(t.substr(i, an) == a){
                t.erase(i, an);
                s = max(i - an, 0);
                e = max(e, i + an);
                flag = true;
                break;
            }
        }
        if(!flag){ break; }
        if(e > t.size()-1){ e = t.size()-1; }

        flag = false;
        for(int i=e-an+1; i>=0; --i){
            if(t.substr(i, an) == a){
                t.erase(i, an);
                e = min(i + an, int(t.size())-1);
                s = min(s, i - an);
                flag = true;
                break;
            }
        }
        if(!flag){ break; }
    }

    cout << t;
    return 0;
}