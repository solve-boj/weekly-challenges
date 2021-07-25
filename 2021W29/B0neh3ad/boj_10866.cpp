/*
    덱
    https://www.acmicpc.net/problem/10866
*/
#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    deque<int> dq;
    int dsize = 0;
    for(int i=0; i<N; ++i){
        string cmd;
        cin >> cmd;

        if(cmd[3] == '_'){
            if(dsize == 0){ cout << -1 << endl; }
            else{
                cout << ((cmd[4] == 'f') ? dq.front() : dq.back()) << endl;
                (cmd[4] == 'f') ? dq.pop_front() : dq.pop_back();
                dsize--;
            }
        }
        else if(cmd[4] == '_'){
            int item;
            cin >> item;
            (cmd[5] == 'f') ? dq.push_front(item) : dq.push_back(item);
            dsize++;
        }
        else if(cmd == "size"){
            cout << dsize << endl;
        }
        else if(cmd == "empty"){
            cout << (dsize == 0) << endl;
        }
        else if(cmd == "front"){
            if(dsize == 0){ cout << -1 << endl; }
            else{ cout << dq.front() << endl; }
        }
        else if(cmd == "back"){
            if(dsize == 0){ cout << -1 << endl; }
            else{ cout << dq.back() << endl; }
        }
    }
    return 0;
}