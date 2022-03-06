/*
    가장 긴 증가하는 팰린드롬 부분수열
    https://www.acmicpc.net/problem/16161
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<size_t> S(N);
	for(auto& s:S)
		cin >> s;

	bool up = true;
	size_t up_len = 1;
	size_t down_len = 0;
	size_t mid = -1;
	size_t ans = 1;
	bool mid_same = false;

	for(size_t i=1; i!=N; ++i){
		if(up){
			if(S[i-1] < S[i])
				++up_len;
			else{
				mid_same = S[i-1] == S[i];
				up = false;
				down_len = 0;
				mid = i-1;
			}
		}

		if(!up){
			if(
				(S[i-1] > S[i] || mid_same)
				 && S[i] == S[mid - down_len - !mid_same]){
				++down_len;
			}else{
				up = true;
				up_len = 1;
			}

			ans = max(ans, (!mid_same) + min(up_len-!mid_same, down_len)*2);

			if(up_len == down_len + !mid_same){
				ans = max(ans, up_len + down_len);
				up = true;
				up_len = 1;
			}
		}
	}

	cout << ans;
}