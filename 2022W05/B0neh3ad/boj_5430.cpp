#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        string p;
        cin >> p;

        int n;
        cin >> n;

        string inp;
        cin >> inp;

        int arr[n], idx = 0;
        int loc = 1, len = -1;
        for(int i=0; i<inp.size(), idx<n; ++i, ++len){
            if(inp[i] == ',' || inp[i] == ']'){
                arr[idx++] = stoi(inp.substr(loc, len));
                loc = i+1;
                len = -1;
            }
        }

        int s = 0, e = n-1;
        int front_flag = 1, error_flag = 0;
        for(char func: p){
            switch(func){
                case 'R':
                front_flag ^= 1;
                break;

                case 'D':
                if(s > e){ // already empty
                    error_flag = 1;
                    break;
                }
                if(front_flag){
                    s += 1;
                }
                else {
                    e -= 1;
                }
                break;
            }
        }

        if(!error_flag){
            cout << "[";
            if(front_flag){
                for(int i=s; i<=e; ++i){
                    cout << arr[i];
                    if(i<e){ cout << ","; }
                }
            }
            else{
                for(int i=e; i>=s; --i){
                    cout << arr[i];
                    if(i>s){ cout << ","; }
                }
            }
            cout << "]\n";
        }
        else{
            cout << "error\n";
        }
    }
    return 0;
}