/*
    분수 합
    https://www.acmicpc.net/problem/1735
*/
#include <iostream>
using namespace std;
int gcd(int a, int b){
    int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main(){
    int numer1, deno1, numer2, deno2;
    cin>>numer1>>deno1>>numer2>>deno2;
    int sumnumer = numer1*deno2 + numer2*deno1;
    int sumdeno = deno1*deno2;
    int div = gcd(sumnumer, sumdeno);
    cout<<sumnumer/div<<" "<<sumdeno/div;
}