/*
    등수 매기기
    https://www.acmicpc.net/problem/2012
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	using namespace std;

	size_t N;
	cin >> N;

	vector<int> v(N);
	for(auto& c:v)
		cin >> c;

	sort(v.begin(), v.end());

	size_t ans = 0;
	for(int i=0; i!=N; ++i)
		ans += abs(i+1 - v[i]);

	cout << ans;
}