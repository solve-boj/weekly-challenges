/*
    N과 M (9)
    https://www.acmicpc.net/problem/15663
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int check[10001];
vector<int> set;

void solution(int curr, int cnt, vector<int> &array){
    if (cnt == m){
        if(array.size() == m){
            for(vector<int>::iterator it = array.begin(); it != array.end(); it++) { cout << *it << " "; }
            cout << '\n';
        }
    }
    else{
        for(int i=0; i<set.size(); ++i){
            if(check[set[i]] > 0){
                check[set[i]]--;
                array.push_back(set[i]);

                solution(i, cnt+1, array);

                check[set[i]]++;
                array.pop_back();
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int temp[n];
    
    for(int i=0; i<n; ++i){
        cin >> temp[i];
        check[temp[i]]++;
    }
    sort(temp, temp+n);
    for(int i=0; i<n; ++i){
        if((i == 0) || (set.back() != temp[i])){
            set.push_back(temp[i]);
        }
    }

    vector<int> arr;
    solution(-1, 0, arr);
    return 0;
}

/*
    1. input list로 set을 만든다
    2. 그와 동시에 set의 각 원소별 개수 counting
    3. 재귀 돌리면서 원소 하나 꺼내 쓸 때마다 count - 1 해두기 (다 썼으면 count 원상복구)
*/