/*
    좋은수열
    https://www.acmicpc.net/problem/2661
*/

#include <iostream>
#include <string>

using namespace std;

int N;
string seq;
bool done = false;


void f(int n) {
    if(done) return;
    bool flag = true;
    seq.push_back((char)('0' + n));
    for(int i=1;i<=seq.size()/2;i++) {
        if(seq.substr(seq.size()-i, i) == seq.substr(seq.size()-2*i, i)) {
            flag=false;
            break;
        }
    }
    if(!flag) {
        seq.pop_back();
        return;
    }
    if(seq.size() == N) {
        cout << seq;
        done = true;
        seq.pop_back();
        return;
    }
    for(int c=1;c<=3;c++) {
        f(c);
    }
    seq.pop_back();
}

int main() {
    scanf("%d", &N);
    for(int c=1;c<=3;c++) {
        f(c);
    }
}