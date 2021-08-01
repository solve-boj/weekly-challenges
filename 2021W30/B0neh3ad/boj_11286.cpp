#include <cstdio>
#include <cstdlib>
#include <cmath>

const int MAX_SIZE = 200000;

template<typename T>
class PriorityQueue{
public:
    T heap[MAX_SIZE];
    int size;

    PriorityQueue(): size(0){}

    void push(T data){
        heap[size] = data;
        int curr = size;
        int parent = (size-1)/2;
        while(curr > 0 && cmp(heap[curr], heap[parent])){
            swap(&heap[curr], &heap[parent]);
            curr = parent;
            parent = (parent-1)/2;
        }
        ++size;
    }

    T pop(){
        if(size == 0){ return 0; }

        T res = heap[0];
        --size;
        heap[0] = heap[size];
        int curr = 0, lc = 1, rc = 2;
        int target = curr;

        while(lc < size){
            if(cmp(heap[lc], heap[target])){ target = lc; } // target이랑 비교!!
            if(cmp(heap[rc], heap[target]) && rc < size){ target = rc; }

            if(target == curr){ break; }
            else{
                swap(&heap[target], &heap[curr]);
                curr = target;
                lc = curr*2 + 1;
                rc = curr*2 + 2;
            }
        }
        
        return res;
    }

private:
    void swap(T *lhs, T *rhs){
        T temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    }

    bool cmp(T &lhs, T &rhs){ return ((abs(lhs) == abs(rhs)) ? (lhs < rhs) : (abs(lhs) < abs(rhs))); }
};

int main(void){
    int N;
    scanf("%d", &N);

    PriorityQueue<long long> pq;
    long long temp;
    for(int i=0; i<N; ++i){
        scanf("%lld", &temp);
        if(temp == 0){ printf("%lld\n", pq.pop()); }
        else{ pq.push(temp); }
    }
    return 0;
}