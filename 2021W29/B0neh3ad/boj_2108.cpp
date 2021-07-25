#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs){
    return (lhs.first != rhs.first) ? (lhs.first > rhs.first) : (lhs.second < rhs.second);
}

int main(void){
    int N;
    cin >> N;

    int arr[N];
    vector<pair<int, int> > check(8001, make_pair(0, 0));
    double sum = 0;
    for(int i=0; i<8001; ++i)
        check[i].second = i - 4000;
    
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        sum += arr[i];
        check[arr[i]+4000].first++;
    }

    cout << round(sum / N) << endl;

    sort(arr, arr+N);
    cout << arr[(N-1)/2] << endl;
    
    sort(check.begin(), check.end(), cmp);
    cout << ((check[0].first == check[1].first) ? check[1].second : check[0].second) << endl;

    cout << arr[N-1] - arr[0] << endl;
}