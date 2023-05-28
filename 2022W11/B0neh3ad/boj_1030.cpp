#include <bits/stdc++.h>
using namespace std;

int size;
int s, n, k;
int r1, r2, c1, c2;


bool sol(int y, int x, int sy, int sx, int unit){
    if(unit < 1){
        return false;
    }

    bool res = false;

    int rel_y = (y-sy) / unit;
    int rel_x = (x-sx) / unit;

    // if inside black
    if(rel_y >= (n-k)/2 && rel_y <= (n-1)-(n-k)/2 && rel_x >= (n-k)/2 && rel_x <= (n-1)-(n-k)/2){
        res = true;
    }
    else{
        sy += rel_y * unit;
        sx += rel_x * unit;
        res = sol(y, x, sy, sx, unit / n);
    }

    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    
    int unit = int(pow(double(n), double(s)));
    
    for(int y=r1; y<=r2; ++y){
        for(int x=c1; x<=c2; ++x){
            cout << sol(y, x, 0, 0, unit / n);
        }
        cout << '\n';
    }
    

    return 0;
}