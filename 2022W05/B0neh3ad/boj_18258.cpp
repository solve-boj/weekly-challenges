#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    queue<int> q;

    cin >> n;
    for(int i=0; i<n; ++i){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int val;
            cin >> val;
            q.push(val);
        }
        else if(cmd == "pop"){
            if(q.empty()){
                cout << "-1\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(cmd == "size"){
            cout << q.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << (q.empty() ? "1\n" : "0\n");
        }
        else if(cmd == "front"){
            if(q.empty()){
                cout << "-1\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }
        else if(cmd == "back"){
            if(q.empty()){
                cout << "-1\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }
    return 0;
}