#include <bits/stdc++.h>
using namespace std;

int main(void){
    string name[3] = {"TroyMartian\n", "VladSaturnian\n", "GraemeMercurian\n"};

    int a, e;
    cin >> a >> e;
    
    if(a >= 3 && e <= 4){
        cout << name[0];
    }
    if(a <= 6 && e >= 2){
        cout << name[1];
    }
    if(a <= 2 && e <= 3){
        cout << name[2];
    }


    return 0;
}