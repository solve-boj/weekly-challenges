/*
    이중 우선순위 큐
    https://www.acmicpc.net/problem/7662
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int k;
        cin >> k;

        map<int, int> cnt;
        set<int> pq; // 오름차순 정렬

        while(k--){
            char inp;
            int n;
            cin >> inp >> n;

            switch(inp){
                case 'D': {
                    if(pq.empty()){
                        continue;
                    }

                    set<int>::iterator temp_it = pq.begin();
                    if(n == 1){
                        temp_it = pq.end();
                        --temp_it;
                    }

                    int val = *temp_it;
                    if(cnt[val] == 1){
                        pq.erase(val);
                    }

                    --cnt[val];
                    break;
                }

                case 'I': {
                    if(cnt.find(n) != cnt.end()){
                        if(cnt[n] == 0){
                            pq.insert(n);
                        }
                        ++cnt[n];
                    }
                    else{
                        pq.insert(n);
                        cnt.insert({n, 1});
                    }
                    break;
                }
            }
        }

        if(pq.empty()){
            cout << "EMPTY\n";
        }
        else{
            int min_val = *(pq.begin());
            set<int>::iterator temp_it = pq.end();
            --temp_it;
            int max_val = *temp_it;

            cout << max_val << ' ' << min_val << '\n';
        }
    }
    return 0;
}