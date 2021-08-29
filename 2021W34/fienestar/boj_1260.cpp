/*
    약수의 합
    https://www.acmicpc.net/source/32767739
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	constexpr size_t n_max = 1'000'000;
	using ull = unsigned long long;
	vector<ull> f(n_max+1, 1);
	for(size_t i=2; i<=n_max; ++i)
		for(size_t j=i; j<=n_max; j+=i)
			f[j] += i;

	vector<ull> g(n_max+1);
	for(ull i=0; i!=n_max; ++i)
		g[i+1] = g[i] + f[i+1];

	size_t T;
	cin >> T;

	while(T--) {
		size_t N;
		cin >> N;

		cout << g[N] << "\n";
	}
}