#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int set = 0;
    int m;
    cin >> m;
    
    while(m--){
        string cmd;
        cin >> cmd;

        if(cmd == "all"){
            set = (1 << 21) - 1;
        }
        else if(cmd == "empty"){
            set = 0;
        }
        else{
            int x;
            cin >> x;

            if(cmd == "add"){
                set |= (1 << x);
            }
            else if(cmd == "remove"){
                set &= ~(1 << x);
            }
            else if(cmd == "check"){
                cout << ((set & (1 << x)) ? 1 : 0) << "\n";
            }
            else if(cmd == "toggle"){
                set ^= (1 << x);
            }
        }
    }
    return 0;
}