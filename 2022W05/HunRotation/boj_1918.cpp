/*
    후위 표기식
    https://www.acmicpc.net/problem/1918
*/

#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <cctype>

using namespace std;

string str;
stack<char> st;
map<char, int> priority;

int main() {
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;
    priority['('] = -1;

    cin >> str;
    for(char c: str) {
        if(isalpha(c)) {
            cout << c;
        }
        else {
            if(c == ')') {
                while(st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && c != '(' && priority[st.top()] >= priority[c]) {
                    cout << st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}