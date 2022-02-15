#include <bits/stdc++.h>
using namespace std;

int lis[101][101][101];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;
    cin >> a >> b >> c;

    for(int i=1; i<=a.size(); ++i){
        for(int j=1; j<=b.size(); ++j){
            for(int k=1; k<=c.size(); ++k){
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1]){
                    lis[i][j][k] = lis[i-1][j-1][k-1] + 1;
                } else {
                    lis[i][j][k] = max(lis[i-1][j][k], max(lis[i][j-1][k], lis[i][j][k-1]));
                }
            }
        }
    }

    cout << lis[a.size()][b.size()][c.size()];
    return 0;
}