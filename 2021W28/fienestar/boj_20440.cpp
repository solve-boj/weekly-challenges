/*
    🎵니가 싫어 싫어 너무 싫어 싫어 오지 마 내게 찝쩍대지마🎵 - 1
    https://www.acmicpc.net/problem/20440
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<pair<size_t, int>> T(N*2);
	for(size_t i=0; i!=N; ++i){
		size_t TE, TX;
		cin >> TE >> TX;
		T[i<<1] = {TE, 1};
		T[i<<1|1] = {TX, -1};
	}

	sort(T.begin(), T.end());

	int M = 0;
	int now = 0;

	size_t begin = 0;
	size_t end = 0;
	for(auto& [time,count]:T){
		if(end == 0 && now == M)
			end = time;
		now += count;
		if(end == time && now == M && count == 1)
			end = 0;
		if(now > M){
			M = now;
			begin = time;
			end = 0;
		}
	}

	cout << M << "\n";
	cout << begin << " " << end << "\n";
}