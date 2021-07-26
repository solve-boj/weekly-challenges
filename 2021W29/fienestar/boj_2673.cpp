/*
    교차하지 않는 원의 현들의 최대집합
    https://www.acmicpc.net/problem/2673
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	bool E[100][100] = {};
	while(N--){
		size_t a, b;
		cin >> a >> b;
		--a; --b;

		E[a][b] = E[b][a] = true;
	}

	size_t dp[100][101] = {};
	for(size_t j=1; j<=100; ++j)
		for(size_t i=j; i--; )
			for(size_t k=i; k!=j; ++k)
				dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]+E[i][k]);

	cout << dp[0][100];
}