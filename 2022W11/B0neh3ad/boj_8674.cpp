#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long a, b;
    cin >> a >> b;
    if(a < b){ swap(a, b); }
    if(a%2 && b%2){
        cout << b;
    } else {
        cout << 0;
    }
    return 0;
}