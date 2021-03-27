/*
    스타트링크
    https://www.acmicpc.net/problem/5014
*/
#include <bits/stdc++.h>

using namespace std;

bool is_in_range(size_t n,size_t begin,size_t end)
{
	return begin <= n && n <= end;
}

int main()
{
	size_t F,S,G,U,D;
	cin >> F >> S >> G >> U >> D;

	queue<size_t> q;
	vector<size_t> cost(F+1,-1);
	vector<bool> visiting(F+1);

	auto check = [&](size_t n, size_t new_cost){
		if(is_in_range(n,1,F) && cost[n] > new_cost){
			if(not visiting[n])q.emplace(n);
			cost[n] = new_cost;
			visiting[n] = true;
		}
	};

	cost[S] = 1;
	q.emplace(S);

	while(!q.empty()){
		size_t n = q.front();
		q.pop();
		visiting[n] = false;
		
		check(n+U,cost[n]+1);
		check(n-D,cost[n]+1);
	}

	if(cost[G] == -1)
		cout << "use the stairs";
	else
		cout << cost[G] - 1;
}