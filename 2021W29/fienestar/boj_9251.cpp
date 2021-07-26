/*
    LCS
    https://www.acmicpc.net/problem/9251
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	string A, B;
	cin >> A >> B;

	vector<vector<size_t>> dp(A.size()+1, vector<size_t>(B.size()+1));
	for(size_t i=0; i!=A.size(); ++i)
		for(size_t j=0; j!=B.size(); ++j)
			if(A[i] == B[j])
				dp[i+1][j+1] = dp[i][j] + 1;
			else
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);

	cout << dp[A.size()][B.size()];
}