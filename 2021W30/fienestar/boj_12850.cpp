/*
    본대 산책2
    https://www.acmicpc.net/problem/12850
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using matrix_t = vector<vector<ull>>;
constexpr ull mod = 1'000'000'007ull;

matrix_t operator *(const matrix_t& a, const matrix_t& b)
{
	matrix_t result(8, vector<ull>(8,0));
	for(size_t i=0; i!=8; ++i)
		for(size_t j=0; j!=8; ++j)
			for(size_t k=0; k!=8; ++k)
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
	return result;
}

matrix_t pow(matrix_t a, size_t n)
{
	matrix_t result(8, vector<ull>(8,0));
	for(size_t i=0; i!=8; ++i)
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
	size_t d;
	cin >> d;

	matrix_t init(8, vector<ull>(8,0));
	init[0][0] = 1;

	matrix_t edge(8, vector<ull>(8,0));
	edge[0][1] = edge[1][0]
		= edge[0][2] = edge[2][0]
		= edge[1][2] = edge[2][1]
		= edge[1][3] = edge[3][1]
		= edge[2][3] = edge[3][2]
		= edge[2][4] = edge[4][2]
		= edge[3][4] = edge[4][3]
		= edge[3][5] = edge[5][3]
		= edge[4][5] = edge[5][4]
		= edge[4][7] = edge[7][4]
		= edge[5][6] = edge[6][5]
		= edge[6][7] = edge[7][6]
		= 1;
	
	cout << (init * pow(edge, d))[0][0];
}