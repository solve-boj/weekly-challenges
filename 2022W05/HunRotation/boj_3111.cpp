/*
    검열
    https://www.acmicpc.net/problem/3111
*/

#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<char> origin;
deque<char> dq_front, dq_back;

string str, target;
int cfront, cback;
bool front_turn = true;

void print() {
    cout << "front: ";
    for(int i=0;i<dq_front.size();i++) {
        cout << dq_front[i];
    }
    cout << endl;
    cout << "back: ";
    for(int i=0;i<dq_back.size();i++) {
        cout << dq_back[i];
    }
    cout << endl;
}

bool check_front(deque<char>& dq) {
    bool flag = true;
    auto iter = dq.begin();
    if (dq.size() < target.size()) flag = false;
    else for(int i=0;i<target.size();i++, iter++) {
        if (target[i] != (*iter)) {
            flag = false;
            break;
        }
    }
    if(flag) {
        for(int i=0;i<target.size();i++) {
            dq.pop_front();
        }
    }
    return flag; 
}

bool check_back(deque<char>& dq) {
    bool flag = true;
    auto iter = dq.rbegin();
    if (dq.size() < target.size()) flag = false;
    else for(int i=0;i<target.size();i++, iter++) {
        if (target[target.size()-1-i] != (*iter)) {
            flag = false;
            break;
        }
    }
    
    if(flag) {
        for(int i=0;i<target.size();i++) {
            dq.pop_back();
        }
    }
    return flag;
}

int main() {
    cin >> target;
    cin >> str;
    cfront = 0;
    cback = str.size()-1;
    for(char c: str) {
        origin.push_back(c);
    }
    while(!origin.empty()) {
        if(front_turn) {
            dq_front.push_back(origin.front());
            ++cfront;
            origin.pop_front();
            if(check_back(dq_front)) front_turn = !front_turn;
        }
        else {
            dq_back.push_front(origin.back());
            --cback;
            origin.pop_back();
            if(check_front(dq_back)) front_turn = !front_turn;
        }
        //print();
    }
    while(!dq_front.empty() && !dq_back.empty()) {
        if(front_turn) {
            dq_front.push_back(dq_back.front());
            dq_back.pop_front();
            if(check_back(dq_front)) front_turn = !front_turn;
        }
        else {
            dq_back.push_front(dq_front.back());
            dq_front.pop_back();
            if(check_front(dq_back)) front_turn = !front_turn;
        }
        //print();
    }
    if(dq_front.empty()) {
        while(!dq_back.empty()) {
            cout << dq_back.front();
            dq_back.pop_front();
        }
    }
    else {
        while(!dq_front.empty()) {
            cout << dq_front.front();
            dq_front.pop_front();
        }
    }
}