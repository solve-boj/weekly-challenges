/*
    N과 M (8)
    https://www.acmicpc.net/problem/15657
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> set;

void solution(int curr, int cnt, vector<int> &array){
    if (cnt == m){
        if(array.size() == m){
            for(vector<int>::iterator it = array.begin(); it != array.end(); it++) { cout << *it << " "; }
            cout << '\n';
        }
    }
    else{
        for(int i=curr; i<n; ++i){
            array.push_back(set[i]);
            solution(i, cnt+1, array);
            array.pop_back();
        }
    }
}

int main(void){
    cin >> n >> m;
    set.resize(n);

    for(int i=0; i<n; ++i){ cin >> set[i]; }
    sort(set.begin(), set.end());

    vector<int> arr;
    solution(0, 0, arr);
    return 0;
}