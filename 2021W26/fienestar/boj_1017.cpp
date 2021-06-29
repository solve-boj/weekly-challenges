/*
    소수 쌍
    https://www.acmicpc.net/problem/1017
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

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<size_t> v(N);
	for(auto& c:v)
		cin >> c;

	prime_checker is_prime(2000);
	size_t p[50];
	bool visited[50];
	function<bool(size_t)> can = [&](size_t i){
		visited[i] = true;
		for(size_t j=1; j!=N; ++j)
			if(i != j && is_prime(v[i] + v[j]) && (p[j] == -1 || !visited[p[j]] && can(p[j]))){
				p[i] = j;
				p[j] = i;
				return true;
			}

		return false;
	};

	vector<size_t> answer;
	answer.reserve(N-1);

	for(size_t i=1; i!=v.size(); ++i)
		if(is_prime(v[0]+v[i])){
			memset(p, -1, sizeof(p));
			p[0] = i;
			p[i] = 0;

			size_t j;
			for(j=1; j!=N; ++j)
				if(p[j] == -1){
					memset(visited, 0, sizeof(visited));
					visited[0] = visited[i] = true;

					if(!can(j))
						break;
				}

			if(j == N)
				answer.push_back(v[i]);
		}

	if(!answer.size())
		cout << "-1";
	else{
		sort(answer.begin(), answer.end());
		for(auto c:answer)
			cout << c << " ";
	}
}