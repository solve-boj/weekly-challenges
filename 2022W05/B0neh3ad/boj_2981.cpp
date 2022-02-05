#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    int res = arr[1] - arr[0];
    for(int i=0; i<n-1; ++i){
        res = gcd(res, arr[i+1] - arr[i]);
    }

    vector<int> divs;
    for(int i=1; i*i<=res; ++i){
        if(res%i == 0){
            divs.push_back(i);
            divs.push_back(res/i);
        }
    }

    sort(divs.begin(), divs.end());
    int skip_idx = -1;
    if(divs[divs.size()/2] == divs[divs.size()/2-1]){
        skip_idx = divs.size()/2;
    }
    for(int i=1; i<divs.size(); ++i){
        if(i != skip_idx){
            cout << divs[i] << " ";
        }
    }
    
    return 0;
}