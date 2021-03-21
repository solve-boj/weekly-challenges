/*
    링
    https://www.acmicpc.net/problem/3036
*/
#include <iostream>
using namespace std;
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main(){
    int N;
    cin>>N;
    int ring[101];
    cin>>ring[0];
    for(int i=1;i<N;i++){
        cin>>ring[i];
        int div = gcd(ring[0], ring[i]);
        cout<<ring[0]/div<<"/"<<ring[i]/div<<"\n";

    }
}