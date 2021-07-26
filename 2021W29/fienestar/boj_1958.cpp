/*
    LCS 3
    https://www.acmicpc.net/problem/9258
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
auto make_vector(size_t n, T&& value)
{
	return vector<T>(n, std::forward<T>(value));
}

template <class ...Args>
auto make_vector(size_t n, Args&&... args)
{
	auto value = make_vector(std::forward<Args>(args)...);
	return vector<decltype(value)>(n, std::move(value));
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	string A, B, C;
	cin >> A >> B >> C;

	auto dp = make_vector(A.size()+1, B.size()+1, C.size()+1, size_t(0));
	for(size_t i=0; i!=A.size(); ++i)
		for(size_t j=0; j!=B.size(); ++j)
			for(size_t k=0; k!=C.size(); ++k)
				if(A[i] == B[j] && B[j] == C[k])
					dp[i+1][j+1][k+1] = dp[i][j][k] + 1;
				else
					dp[i+1][j+1][k+1] = max({dp[i][j+1][k+1], dp[i+1][j][k+1], dp[i+1][j+1][k]});

	cout << dp[A.size()][B.size()][C.size()] << "\n";
}