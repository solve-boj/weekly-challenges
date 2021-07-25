/*
    큐
    https://www.acmicpc.net/problem/10845
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class UnderflowException{};

template<typename T>
class ListNode{
public:
    T value;
    ListNode<T> *next;

    ListNode<T>(): next(nullptr){}
    ListNode<T>(T value1, ListNode<T> *next1): value(value1), next(next1){}
};

template <typename T>
class Queue{
public:
    int qsize;
    ListNode<T> *head, *tail;

    // 생성자
    Queue<T>(): qsize(0), head(nullptr), tail(nullptr){}

    // 소멸자
    ~Queue<T>(){
        ListNode<T> *t1 = head, *t2;
        while(t1 != nullptr){
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }

    // 멤버 함수
    void push(T value){ // 맨 뒤에 새 원소 삽입
        // 큐가 비어 있었을 경우
        if(qsize == 0) head = tail = new ListNode<T>(value, nullptr);
        else{
            tail->next = new ListNode<T>(value, nullptr);
            tail = tail->next;
        }
        qsize++;
    }

    int pop(){ // 맨 앞의 원소 제거
        // 예외 처리: 큐가 비어 있음
        if(qsize == 0) return -1;

        ListNode<T> *temp = head;
        int temp_val = temp->value;
        head = head->next;
        delete temp;
        if(head == nullptr) tail = nullptr; // 크기가 0이 됨
        qsize--;
        return temp_val;
    }

    int size(){ // 큐의 크기 반환
         return qsize;
    }

    int empty(){ // 큐가 비어있는지 여부 반환 
        return int(qsize == 0);
    }

    T front(){ // 맨 앞의 원소 반환
        // 예외 처리: 큐가 비어 있음
        if(qsize == 0) return -1;

         return head->value;
    }

    T back(){ // 맨 뒤의 원소 반환
        // 예외 처리: 큐가 비어 있음
        if(qsize == 0) return -1;

         return tail->value;
    }
};

int main(){
    int N;
    cin >> N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Queue<int> q;
    for(int i=0; i<N; ++i){
        string cmd;
        cin >> cmd;
        if(cmd == "pop"){
            cout << q.pop() << endl;
        }
        else if(cmd == "size"){
            cout << q.size() << endl;
        }
        else if(cmd == "empty"){
            cout << q.empty() << endl;
        }
        else if(cmd == "front"){
            cout << q.front() << endl;
        }
        else if(cmd == "back"){
            cout << q.back() << endl;
        }
        else{
            int item;
            cin >> item;
            q.push(item);
        }
    }
}