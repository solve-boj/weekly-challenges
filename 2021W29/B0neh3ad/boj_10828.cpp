/*
    스택
    https://www.acmicpc.net/problem/10828
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <typename T>
class ListNode{
public:
    T value;
    ListNode<T> *prev;
    ListNode<T> *next;

    // 생성자
    ListNode(): prev(nullptr), next(nullptr) {}
    ListNode(T value1, ListNode<T> *prev1, ListNode<T> *next1) : value(value1), prev(prev1), next(next1) {}
};

template <typename T>
class Stack{
public:
    int ssize;
    ListNode<T> *head;
    ListNode<T> *tail;

    // 생성자
    Stack(): ssize(0), head(nullptr) {}

    // 소멸자
    ~Stack(){
        ListNode<T> *t1 = head, *t2;
        while(t1 != nullptr){
            t2 = t1;
            t1 = t1->next;
            delete t2;
        }
    }

    void push(T item){ // 맨 위에 새 원소 삽입
        // 스택이 비어있었을 경우
        if(ssize == 0) { head = new ListNode<T>(item, nullptr, nullptr); }
        else{
            head->prev = new ListNode<T>(item, nullptr, head);
            head = head->prev;
        }
        ssize++;
    }

    T pop(){
        if(ssize == 0){ return -1; }
        else{
            ListNode<T> *temp = head;
            int temp_val = temp->value;
            head = head->next;
            delete temp;
            ssize--;
            return temp_val;
        }
    }

    int size(){
        return ssize;
    }

    int empty(){
        return int(ssize == 0);
    }

    T top(){
        if(ssize == 0){ return -1; }
        else{
            return head->value;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    Stack<int> st;
    for(int i=0; i<N; ++i){
        string cmd;
        cin >> cmd;
        if(cmd == "pop"){
            cout << st.pop() << endl;
        }
        else if(cmd == "size"){
            cout << st.size() << endl;
        }
        else if(cmd == "empty"){
            cout << st.empty() << endl;
        }
        else if(cmd == "top"){
            cout << st.top() << endl;
        }
        else{
            int item;
            cin >> item;
            st.push(item);
        }
    }
}