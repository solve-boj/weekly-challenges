/*
    어려운 소인수분해
    https://www.acmicpc.net/problem/16563
*/
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	constexpr size_t max_n = 5'000'000;
	static size_t mf[max_n+1];

	if(!mf[4])
		for(size_t i=2; i*i<=max_n; ++i)
			if(!mf[i])
				for(size_t j=i*i; j<=max_n; j+=i)
					if(!mf[j])
						mf[j] = i;

	size_t K;
	cin >> K;

	while(mf[K]){
		cout << mf[K] << " ";
		K /= mf[K];
	}

	cout << K << " ";

	cout << "\n";
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;
	while(N--)
		solve();
}