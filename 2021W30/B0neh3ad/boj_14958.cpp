/*
    Rock Paper Scissors
    https://www.acmicpc.net/problem/14958
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <complex>
#include <algorithm>

const double PI = acos(-1);
typedef std::complex<double> cpx;

int n, m;
std::map<char, int> com_rps, my_rps;

void FFT(std::vector<cpx> &f, cpx w){
    //0. base case
    int n = f.size();
    if(n == 1){ return; }

    std::vector<cpx> even(n/2), odd(n/2);
    for(int i=0; i<n; ++i){
        (i%2 ? odd : even)[i/2] = f[i];
    }

    FFT(even, w*w);
    FFT(odd, w*w);

    cpx wp(1, 0);
    for(int i=0; i<n/2; ++i){
        f[i] = even[i] + wp*odd[i];
        f[i+n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}

std::vector<cpx> mul(std::vector<cpx> a, std::vector<cpx> b){
    int n = 1;
    while(n < a.size() + 1 || n < b.size() + 1){ n *= 2; }
    n *= 2;
    a.resize(n);
    b.resize(n);
    std::vector<cpx> c(n);

    cpx w(cos(2*PI/n), sin(2*PI/n));
    FFT(a, w);
    FFT(b, w);

    for(int i=0; i<n; ++i){ c[i] = a[i]*b[i]; }

    FFT(c, cpx(1, 0)/w);
    for(int i=0; i<n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }

    return c;
}

int main(void){
    scanf("%d %d ", &n, &m);
    
    char temp;
    std::vector<std::vector<cpx> > com(3), my(3);
    for(int i=0; i<3; ++i){
        com[i].resize(n, cpx(0, 0));
        my[i].resize(n, cpx(0, 0));
    }

    com_rps['R'] = my_rps['P'] = 0;
    com_rps['P'] = my_rps['S'] = 1;
    com_rps['S'] = my_rps['R'] = 2;

    for(int i=0; i<n; ++i){
        scanf("%c", &temp);
        com[com_rps[temp]][i] = cpx(1, 0);
    }
    getchar();
    for(int i=0; i<m; ++i){
        scanf("%c", &temp);
        my[my_rps[temp]][m-1-i] = cpx(1, 0);
    }

    std::vector<std::vector<cpx> > result(3);
    
    for(int i=0; i<3; ++i)
        result[i] = mul(com[i], my[i]);

    int ans = 0;
    for(int i=m-1; i<n+m; ++i)
        ans = std::max(ans, int(result[0][i].real() + result[1][i].real() + result[2][i].real()));

    printf("%d", ans);
    return 0;
}