/*
    LCS 4
    https://www.acmicpc.net/problem/13711
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<int> A(N);
	for(auto& c:A)
		cin >> c;

	vector<size_t> value_of(N);
	for(size_t i=0; i!=N; ++i){
		int c;
		cin >> c;
		value_of[c-1] = i;
	}

	vector<int> sub(N);
	size_t len = 0;

	for (size_t i = 0; i != N; ++i) {
		size_t j = lower_bound(sub.begin(), sub.begin() + len, value_of[A[i]-1]) - sub.begin();
		len = max(len, j + 1);
		sub[j] = value_of[A[i]-1];
	}

	cout << len << "\n";
}