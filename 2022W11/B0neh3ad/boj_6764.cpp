#include <bits/stdc++.h>
using namespace std;

int main(void){
    int inp[4];
    for(int i=0; i<4; ++i){
        cin >> inp[i];
    }

    int inc = 0, dec = 0, con = 0;
    for(int i=0; i<3; ++i){
        int diff = inp[i+1] - inp[i];
        if(diff > 0){
            ++inc;
        }
        else if(diff < 0){
            ++dec;
        }
        else{
            ++con;
        }
    }

    if(inc == 3){
        cout << "Fish Rising";
    }
    else if(dec == 3){
        cout << "Fish Diving";
    }
    else if(con == 3){
        cout << "Fish At Constant Depth";
    }
    else{
        cout << "No Fish";
    }
    
    return 0;
}