/*
    좋은 단어
    https://www.acmicpc.net/problem/3986
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N, cnt = 0;
string str;
stack<char> st;

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> str;
        for(char c: str) {
            if(!st.empty() && st.top() == c) {
                st.pop();
            }
            else st.push(c);
        }
        if(st.empty()) cnt++;
        else {
            while(!st.empty()) st.pop();
        }
    }
    cout << cnt;
}