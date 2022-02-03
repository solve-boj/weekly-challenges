#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int main(void){
    int n;
    cin >> n;

    int lhs;
    cin >> lhs;

    for(int i=1; i<n; ++i){
        int rhs;
        cin >> rhs;

        int temp = gcd(lhs, rhs);
        cout << lhs/temp << '/' << rhs/temp << '\n';
    }

    return 0;
}