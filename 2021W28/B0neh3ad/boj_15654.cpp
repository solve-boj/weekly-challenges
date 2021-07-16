/*
    N과 M (5)
    https://www.acmicpc.net/problem/15654
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> set;
vector<bool> visit;

void solution(int cnt, vector<int> &array){
    if (cnt == m){
        if(array.size() == m){
            for(vector<int>::iterator it = array.begin(); it != array.end(); it++) { cout << *it << " "; }
            cout << '\n';
        }
    }
    else{
        for(int i=0; i<n; ++i){
            if(!visit[i]){
                visit[i] = true;
                array.push_back(set[i]);

                solution(cnt+1, array);

                visit[i] = false;
                array.pop_back();
            }
        }
    }
}

int main(void){
    cin >> n >> m;
    set.resize(n);
    visit.resize(n);

    for(int i=0; i<n; ++i){ cin >> set[i]; }
    sort(set.begin(), set.end());
    fill(visit.begin(), visit.end(), false);

    vector<int> arr;
    solution(0, arr);
    return 0;
}