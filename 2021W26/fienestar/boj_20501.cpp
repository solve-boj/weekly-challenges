/*
    Facebook
    https://www.acmicpc.net/problem/20501
*/
#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
constexpr size_t ull_bit_count = sizeof(ull) * 8;
constexpr size_t C = 32; // ceil(2000/ull_bit_count)
using bitarray = ull[C];

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<bitarray> is_friend(N);
	for(size_t i=0; i!=N; ++i)
		for(size_t j=0; j!=N; ++j){
			char c;
			cin >> c;
			is_friend[i][j/ull_bit_count] |= ull(c=='1') << (j%ull_bit_count);
		}

	size_t Q;
	cin >> Q;

	while(Q--){
		size_t A, B;
		cin >> A >> B;
		--A; --B;

		size_t answer = 0;
		for(size_t i=0; i!=C; ++i)
			answer += __builtin_popcountll(is_friend[A][i] & is_friend[B][i]);

		cout << answer << "\n";
	}
}