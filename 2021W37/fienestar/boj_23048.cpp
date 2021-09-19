/*
    자연수 색칠하기
    https://www.acmicpc.net/problem/23048
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<size_t> pc(N);
	size_t *ppc = &pc[0]-1;
	size_t k = 0;
	ppc[1] = ++k;
	for(size_t i=2; i<=N; ++i)
		if(ppc[i] == 0){
			ppc[i] = ++k;
			for(size_t j=i*i; j<=N; j+=i)
				ppc[j] = k;
		}

	cout << k << "\n";
	for(auto& c:pc)
		cout << c << " ";
}