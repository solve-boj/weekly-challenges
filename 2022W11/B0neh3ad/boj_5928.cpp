#include <bits/stdc++.h>
using namespace std;

int main(void){
    int d, h, m;
    cin >> d >> h >> m;

    int res = 0;
    res += (d - 11) * 1440;
    res += (h - 11) * 60;
    res += (m - 11);

    cout << ((res < 0) ? -1 : res);
    return 0;
}