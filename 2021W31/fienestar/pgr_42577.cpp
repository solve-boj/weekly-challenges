/*
    전화번호 목록
    https://programmers.co.kr/learn/courses/30/lessons/42577
*/
#include <bits/stdc++.h>

using namespace std;

struct node
{
    unique_ptr<node> next[10];
    bool end;
};

bool solution(vector<string> phone_book)
{
    auto root = make_unique<node>();
    for(auto& phone:phone_book){
        node *c = &*root;
        bool isLeaf = false;
        for(auto ch:phone){
            ch -='0';
            
            if(!c->next[ch]){
                c->next[ch] = make_unique<node>();
                isLeaf = true;
            }
            
            c = &*c->next[ch];
            
            if(c->end)
                return false;
        }
        c->end = true;
        
        if(!isLeaf)
            return false;
    }
    
    return true;
}