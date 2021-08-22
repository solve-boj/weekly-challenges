/*
    피보나치 수 6
    https://www.acmicpc.net/problem/11444
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using matrix_t = vector<vector<ull>>;
constexpr ull mod = 1'000'000'007ull;

matrix_t operator *(const matrix_t& a, const matrix_t& b)
{
	size_t n = a.size();
	matrix_t result(n, vector<ull>(n,0));
	for(size_t i=0; i!=n; ++i)
		for(size_t j=0; j!=n; ++j)
			for(size_t k=0; k!=n; ++k)
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
	return result;
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t n;
	cin >> n;

	matrix_t result = {{1,0}, {0,1}};
	matrix_t fibo = {{1,1}, {1,0}};

	while(n) {
		if(n&1)
			result = result * fibo;
		fibo = fibo * fibo;
		n >>= 1;
	}

	cout << result[0][1];
}