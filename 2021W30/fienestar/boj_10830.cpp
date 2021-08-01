/*
    행렬 제곱
    https://www.acmicpc.net/problem/10830
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using matrix_t = vector<vector<ull>>;
constexpr ull mod = 1'000ull;

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

matrix_t pow(matrix_t a, size_t n)
{
	matrix_t result(a.size(), vector<ull>(a.size(),0));
	for(size_t i=0; i!=a.size(); ++i)
		result[i][i] = 1;

	while(n){
		if(n&1)
			result = result * a;
		n >>= 1;
		a = a * a;
	}
	return result;
}

int main()
{
	size_t n, B;
	cin >> n >> B;

	matrix_t A(n, vector<ull>(n));
	for(auto& line:A)
		for(auto& dot:line)
			cin >> dot;

	matrix_t answer = pow(A, B);
	for(auto& line:answer){
		for(auto& dot:line)
			cout << dot << " ";
		cout << "\n";
	}
}