#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(void){
    string a, b;
    cin >> a >> b;

    ull lhs = 0, rhs = 0;
    for(char c: a){
        lhs *= 2;
        lhs += c - '0';
    }
    for(char c: b){
        rhs *= 2;
        rhs += c - '0';
    }

    ull res = lhs * rhs;
    vector<int> res_bin;
    while(res){
        res_bin.push_back(res % 2);
        res /= 2;
    }    
    for(auto it = res_bin.rbegin(); it != res_bin.rend(); ++it){
        cout << *it;
    }

    return 0;
}