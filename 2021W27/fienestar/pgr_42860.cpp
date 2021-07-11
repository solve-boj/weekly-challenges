/*
    조이스틱
    https://programmers.co.kr/learn/courses/30/lessons/42860
*/
#include <bits/stdc++.h>

using namespace std;

int solution(string name)
{
    const size_t N = name.size();
    size_t total_todo = 0;
    for(auto& c:name){
        c-='A';
        total_todo += c;
    }
    
    function<size_t(string, size_t, size_t, bool)> find = [&]
        (string name, size_t i, size_t todo, bool k){
        static size_t di[] = {1, N - 1};
        size_t cost = 0;
        
        while(name[i] == 0){
            i = (i + di[k]) % N;
            cost += 1;
        }
        
        size_t next = (i + di[k]) % N;
        while(true){
            cost += min(int(name[i]), 26 - name[i]);
            todo -= name[i];
            name[i] = 0;
            if(name[next] == 0)
                break;
            i = next;
            next = (i + di[k]) % N;
            cost += 1;
        }
        
        if(todo != 0)
            cost += min(find(name, i, todo, 1), find(name, i, todo, 0));
        
        return cost;
    };
    
    return min(find(name, 0, total_todo, 0), find(name, 0, total_todo, 1));
}