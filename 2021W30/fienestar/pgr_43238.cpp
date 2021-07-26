/*
    입국심사
    https://programmers.co.kr/learn/courses/30/lessons/43238
*/
#include <bits/stdc++.h>

using namespace std;

template <class Integer, class ValueType>
class IntegerIterator
{
    Integer _N;
public:
    using iterator_category = random_access_iterator_tag;
    using difference_type   = Integer;
    using value_type        = ValueType;
    using pointer           = Integer*;
    using reference         = Integer&;
    
    static function<ValueType(Integer)> eval;
    
    IntegerIterator(Integer N):_N(N) {}
    auto operator*() { return eval(_N); }
    operator Integer&() { return _N; }
};

template <class Integer, class ValueType>
function<ValueType(Integer)> IntegerIterator<Integer, ValueType>::eval = nullptr;

using ll = long long;
ll solution(int n, vector<int> times)
{
    using It = IntegerIterator<ll, bool>;
    
    It::eval = [&](ll total){
        size_t count = 0;
        for(auto& time:times)
            count += total/time;
        return count >= n;
    };
    
    return lower_bound(
        It(0ll),
        It(1'000'000'000'000'000'000ll),
        true
    );
}