#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n];
    int max_val = -4001, min_val = 4001;
    double sum = 0;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        max_val = max(max_val, arr[i]);
        min_val = min(min_val, arr[i]);
        sum += arr[i];
    }

    sort(arr, arr+n, greater<int>());

    int cnt = 1, val = arr[0];
    int most_cnt = 1;
    queue<int> most_val;
    
    most_val.push(arr[0]);
    for(int i=1; i<n; ++i){
        if(val == arr[i]) {
            ++cnt;
        }
        else {
            val = arr[i];
            cnt = 1;
        }
        if(most_cnt < cnt){
            most_val = queue<int>();
            most_val.push(arr[i]);
            most_cnt = cnt;
        }
        else if(most_cnt == cnt){
            if(most_val.size() > 1){ most_val.pop(); }
            most_val.push(arr[i]);
        }
    }

    cout << ((round(sum/n) == -0) ? 0 : round(sum/n)) << '\n';
    cout << arr[n/2] << '\n';
    cout << most_val.front() << '\n';
    cout << max_val-min_val << '\n';

    return 0;
}