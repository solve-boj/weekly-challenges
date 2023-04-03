#include <bits/stdc++.h>
using namespace std;

int main(void){
    int speed, limit;
    cin >> limit >> speed;

    int res = speed - limit;
    if(res <= 0){
        cout << "Congratulations, you are within the speed limit!";
    }
    else{
        cout << "You are speeding and your fine is $";

        if(res <= 20){
            cout << 100;
        }
        else if(res <= 30){
            cout << 270;
        }
        else{
            cout << 500;
        }
        cout << ".";
    }

    return 0;
}