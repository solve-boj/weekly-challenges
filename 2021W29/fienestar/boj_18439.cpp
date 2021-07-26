/*
    LCS 6
    https://www.acmicpc.net/problem/18439
*/
#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
constexpr size_t ull_bit_count = sizeof(ull) * 8;
constexpr size_t N = 782; // ceil(50001/ull_bit_count)
using bitarray = ull[N];

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	string A, B;
	cin >> A >> B;

	if(A.size() > B.size())swap(A, B);

	bitarray T['Z'-'A'+1] = {};
	for(size_t i=0; i!=B.size(); ++i)
		T[B[i]-'A'][i/ull_bit_count] |= 1ull << (i%ull_bit_count);

	bitarray dp[2] = {};
	for(size_t i=0; i!=A.size(); ++i){
		ull borrow = 1;
		for(size_t j=0; j!=N; ++j){
			ull Y = dp[i&1][j];
			ull X = Y | T[A[i] - 'A'][j];
			
			ull shifted = (Y << 1) | borrow;
			borrow = Y >> (ull_bit_count - 1);
			if(X < shifted)borrow = 1;
			dp[(i+1)&1][j] = X & ((X - shifted) ^ X);
		}
	}

	size_t answer = 0;
	for(size_t i=0; i!=N; ++i)
		answer += __builtin_popcountll(dp[A.size()&1][i]);

	cout << answer;
}