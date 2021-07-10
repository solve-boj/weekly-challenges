/*
    소수 찾기
    https://programmers.co.kr/learn/courses/30/lessons/42839
*/
#include <bits/stdc++.h>

using namespace std;

class prime_checker
{
	vector<bool> is_prime;
public:
	prime_checker(size_t max_value)
		:is_prime(max(size_t(2), max_value+1), true)
	{
		is_prime[0] = is_prime[1] = false;

		for(size_t i=2; i!=is_prime.size(); ++i)
			if(is_prime[i])
				for(size_t j=i*i; j < is_prime.size(); j += i)
					is_prime[j] = false;
	}

	bool operator()(size_t n)
	{
		return is_prime[n];
	}
};

int solution(string numbers)
{
    constexpr size_t N = 10'000'000;
    vector<bool> visited(N, false);
    prime_checker is_prime(N);
    size_t count = 0;
    size_t value = 0;

    function<void(size_t)> visit = [&](size_t i){
        if(i!=0 and not visited[value] and is_prime(value)){
            ++count;
            visited[value] = true;
        }
        for(size_t k=i; k!=numbers.size(); ++k){
            swap(numbers[i], numbers[k]);
            value = value * 10 + (numbers[i] - '0');
            visit(i+1);
            value /= 10;
            swap(numbers[i], numbers[k]);
        }
    };
    
    visit(0);
    
    return count;
}