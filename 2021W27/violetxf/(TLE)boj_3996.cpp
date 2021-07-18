#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long n,k;
    long long cnt = 0;
    long long N;
    cin>>n>>k;
    N=n;
    long long bits = 0;
    while(n>0){
        n/=k;
        bits++;
    }
    int odd = bits%2;
    long long testbits = bits/2+odd-1;
    for(long long i=pow(k, bits-1);i<=N;i++){
        long long num = i;
        long long bit = k;
        bool die = false;
        bool broken = false;
        while(num>0){
            long long remainder = num%bit;
            if(remainder && die){
                broken = true;
                break;
            }
            die = !die;
            num-=remainder*(bit/k);
            bit *= k;
        }
        if(broken)continue;
        cnt++;
    }
    cout << cnt+pow(k, testbits);
}
