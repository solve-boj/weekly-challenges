/*
    N과 M (12)
    https://www.acmicpc.net/problem/15666
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int> set;

void solution(int curr, int cnt, vector<int> &array){
    if(cnt == n){
        if(array.size() == n){
            for(vector<int>::iterator it=array.begin(); it!=array.end(); it++) { cout << *it << " "; }
            cout << '\n';
        }
    }
    else{
        for(int i=curr; i<set.size(); ++i){
            array.push_back(set[i]);
            solution(i, cnt+1, array);
            array.pop_back();
        }
    }
}

int main(void){
    cin >> m >> n;

    int temp[m];
    for(int i=0; i<m; ++i){ cin >> temp[i]; }
    sort(temp, temp+m);
    for(int i=0; i<m; ++i){
        if((i == 0) || (set.back() != temp[i])){
            set.push_back(temp[i]);
        }
    }

    vector<int> arr;
    solution(0, 0, arr);
    return 0;
}