/*
    Web Pages
    https://www.acmicpc.net/problem/5076
*/

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string str, sub;
stack<string> st;
int openpos, closepos;
bool legal;

int main() {
    while(true) {
        legal = true;
        getline(cin, str);
        if (str.size() == 1 && str[0] == '#') break;
        for(int i=0;i<str.size();i++) {
            if (str[i] == '<') openpos = i;
            if (str[i] == '>') {
                closepos = i;
                sub = str.substr(openpos+1, closepos-openpos-1);
                if(str[closepos-1] == '/') continue;
                stringstream ss(sub);
                ss >> sub;
                if(sub[0] == '/') {
                    sub = sub.substr(1, sub.size()-1);
                    if(!st.empty() && sub == st.top()) {
                        st.pop();
                    } else {
                        legal = false;
                        break;
                    }
                } else {
                    st.push(sub);
                }
            }
        }
        if(!st.empty()) {
            legal = false;
        }
        if(legal) {
            cout << "legal" << endl;
        }
        else {
            cout << "illegal" << endl;
        }

        while(!st.empty()) {
            st.pop();
        }
    }
    
}