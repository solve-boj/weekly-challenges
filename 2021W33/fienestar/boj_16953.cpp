/*
    A → B
    https://www.acmicpc.net/problem/16953
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t A, B;
	cin >> A >> B;

	size_t count = 0;
	while(A < B){
		size_t old = B;

		while(!(B&1) && A!=B){
			B >>= 1;
			++count;
		}

		while(B%10 == 1 && A!=B){
			B/=10;
			++count;
		}

		if(old == B)
			break;
	}

	if(A == B)
		cout << count + 1;
	else
		cout << -1;
}