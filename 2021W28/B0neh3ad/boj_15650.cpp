/*
    N과 M (2)
    https://www.acmicpc.net/problem/15650
*/
#include <iostream>
#include <vector>

using namespace std;

int n, m;
void solution(int curr, vector<int> &array){
    if (curr == n+1){
        if(array.size() == m){
            for(vector<int>::iterator it = array.begin(); it != array.end(); it++) { cout << *it << " "; }
            cout << '\n';
        }
    }
    else{
        array.push_back(curr);
        solution(curr+1, array);
        array.pop_back();
        solution(curr+1, array);
    }
}

int main(void){
    cin >> n >> m;

    vector<int> arr;
    solution(1, arr);
    return 0;
}