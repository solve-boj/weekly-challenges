/*
    컨설팅
    https://www.acmicpc.net/problem/20292
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	string s;
	set<string> reading;
	set<string> writing;

	while(cin >> s){
		if(s[0] == 'W'){
			string A, TO, B;
			cin >> A >> TO >> B;

			if(writing.count(A) || reading.count(B)){
				cout << "WAIT\n";
				writing.clear();
				reading.clear();
			}

			writing.insert(B);
			reading.insert(A);

			cout << "WRITE " << A << " TO " << B << "\n";
		}else if(s[0] == 'R'){
			string B;
			cin >> B;

			if(writing.count(B)){
				cout << "WAIT\n";
				writing.clear();
				reading.clear();
			}

			reading.insert(B);

			cout << "READ " << B << "\n";
		}else
			cout << "EXIT\n";
	}
}