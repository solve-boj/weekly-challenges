#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    int s = 0, e;
    int curr = 0;
    for(e=0; e<n; ++e){
        if((k | arr[e]) == k){
            curr |= arr[e];
        }
        else{
            if(curr == k){ break; }
            curr = 0;
            s = e+1;
        }
    }

    if(curr == k){
        cout << s+1 << " " << e;
    }
    else{
        cout << -1;
    }

    return 0;
}