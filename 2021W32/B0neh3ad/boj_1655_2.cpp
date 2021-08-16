/*
    가운데를 말해요
    https://www.acmicpc.net/problem/1655
*/
#include <cstdio>
#include <vector>
#include <queue>

const int MAX_SIZE = 50002;

class PriorityQueue{
public:
    PriorityQueue(): pqsize(0){}

    void push(int val){
        nodes[++pqsize] = val;
        int curr = pqsize;
        int parent = curr / 2;
        while(curr > 1 && cmp(nodes[curr], nodes[parent])){
            swap(&nodes[curr], &nodes[parent]);
            curr = parent;
            parent = curr / 2;
        }
    }

    int pop(){
        int ret = nodes[1];
        nodes[1] = nodes[pqsize];
        --pqsize;

        int curr = 1;
        int target = curr;
        int lc = curr*2, rc = curr*2 + 1;
        while(lc <= pqsize){
            if(cmp(nodes[lc], nodes[target])){ target = lc; }
            if(rc <= pqsize && cmp(nodes[rc], nodes[target])){ target = rc; }
            
            if(target == curr){ break; }
            swap(&nodes[curr], &nodes[target]);
            curr = target;
            lc = curr*2;
            rc = curr*2+1;
        }

        return ret;
    }

    int top(){
        return nodes[1];
    }
protected:
    int pqsize;
    int nodes[MAX_SIZE];

    virtual bool cmp(const int& lhs, const int& rhs){
        return lhs > rhs;
    }

    void swap(int *lhs, int *rhs){
        int temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    }
};

class MinPriorityQueue : public PriorityQueue {
protected:
    bool cmp(const int& lhs, const int& rhs){
        return lhs < rhs;
    }
};

int main(void){
    int n;
    scanf("%d", &n);

    PriorityQueue max_pq; // 작은 원소들
    MinPriorityQueue min_pq; // 큰 원소들

    int inp;
    for(int i=0; i<n; ++i){
        scanf("%d", &inp);
        (i%2) ? min_pq.push(inp) : max_pq.push(inp);
        if(i >= 1){ // 여기 i >= 2로 해서 틀렸었다
            if(max_pq.top() > min_pq.top()){
                max_pq.push(min_pq.pop());
                min_pq.push(max_pq.pop());
            }
        }
        printf("%d\n", max_pq.top());
    }
    return 0;
}
/*
    4
    1 2 3 4
    반례 존재 -> virtual method로 해결
*/