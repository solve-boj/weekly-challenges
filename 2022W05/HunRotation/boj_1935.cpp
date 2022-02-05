/*
    후위 표기식 2
    https://www.acmicpc.net/problem/1935
*/

#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <cctype>

using namespace std;

string str;
stack<double> st;
map<char, double> operands;
int N;

double operate(char oper) {
    double y = st.top();
    st.pop();
    double x = st.top();
    st.pop();
    switch(oper) {
        case '+':
            return x+y;
            break;
        case '-':
            return x-y;
            break;
        case '*':
            return x*y;
            break;
        case '/':
            return x/y;
            break;
    }
    return 0;
}

int main() {
    double temp, res;
    cin >> N;
    cin >> str;
    for(char i=0;i<N;i++) {
        cin >> temp;
        operands['A'+i] = temp; 
    }
    for(char c: str) {
        if(isalpha(c)) {
            st.push(operands[c]);
        }
        else {
            res = operate(c);
            st.push(res);
        }
    }
    printf("%.2f", res);
}