/*
    이중 우선순위 큐
    https://www.acmicpc.net/problem/7662
*/
#include <bits/stdc++.h>

using namespace std;

template <class T, class Cmp>
class removable_priority_queue
{
    priority_queue<T, vector<T>, Cmp> insert_pq;
    priority_queue<T, vector<T>, Cmp> remove_pq;
public:
    void sync()
    {
        while (insert_pq.size() && remove_pq.size() && insert_pq.top() == remove_pq.top()) {
            insert_pq.pop();
            remove_pq.pop();
        }
    }
    void push(T n)
    {
        insert_pq.push(n);
    }

    void remove(T n)
    {
        remove_pq.push(n);
    }

    T top()
    {
        sync();
        return insert_pq.top();
    }

    T pop()
    {
        sync();
        auto result = top();
        insert_pq.pop();
        return result;
    }

    size_t size()
    {
        return insert_pq.size() - remove_pq.size();
    }
};

template <class T>
class dual_priority_queue
{
    removable_priority_queue<T, less<T>> max_pq;
    removable_priority_queue<T, greater<T>> min_pq;
public:
    void push(T n)
    {
        max_pq.push(n);
        min_pq.push(n);
    }

    T pop_min()
    {
        auto result = min_pq.pop();
        max_pq.remove(result);
        return result;
    }

    T pop_max()
    {
        auto result = max_pq.pop();
        min_pq.remove(result);
        return result;
    }

    size_t size()
    {
        return max_pq.size();
    }
};

void solve()
{
    size_t k;
    cin >> k;

    dual_priority_queue<int> pq;
    while (k--) {
        char op;
        int n;

        cin >> op >> n;
        if (op == 'I') {
            pq.push(n);
        }
        else {
            if (pq.size()) {
                if (n == 1)
                    pq.pop_max();
                else
                    pq.pop_min();
            }
        }
    }
    if (pq.size() == 1) {
        auto result = pq.pop_max();
        cout << result << " " << result << "\n";
    }
    else if (pq.size() >= 2)
        cout << pq.pop_max() << " " << pq.pop_min() << "\n";
    else
        cout << "EMPTY\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t T;
    cin >> T;

    while (T--)
        solve();
}