/*
    Golf Bot
    https://www.acmicpc.net/problem/10531
*/
#include <cstdio>
#include <vector>
#include <cmath>
#include <complex>

const double PI = acos(-1);
typedef std::complex<double> cpx;

int N, M;

void FFT(std::vector<cpx> &f, cpx w){
    //0. base case
    int n = f.size();
    if(n == 1){ return; }

    //1. 다항식 쪼개기
    std::vector<cpx> odd(n/2), even(n/2);
    for(int i=0; i<n; ++i){
        (i%2 ? odd : even)[i/2] = f[i]; // ㅋㅋ 여기서 i%2 대신 n%2을 썼었네
    }

    //2. 재귀
    FFT(odd, w*w);
    FFT(even, w*w);

    //3. 합치기
    cpx wp(1, 0);
    for(int i=0; i<n/2; ++i){
        f[i] = even[i] + wp*odd[i];
        f[i+n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}

std::vector<cpx> multiply(std::vector<cpx> a, std::vector<cpx> b){
    //0. size와 omega 값 설정
    int n = 1;
    while((a.size() + 1 > n) || (b.size() + 1 > n)){ n *= 2; }
    n *= 2;
    a.resize(n);
    b.resize(n);
    std::vector<cpx> c(n);

    cpx w(cos(2*PI/n), sin(2*PI/n));

    //1. FFT(O(nlogn))
    FFT(a, w);
    FFT(b, w);

    //2. 곱셈(O(n))
    for(int i=0; i<n; ++i){ c[i] = a[i]*b[i]; }

    //3. IFFT(O(nlogn))
    FFT(c, cpx(1, 0)/w);
    for(int i=0; i<n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }

    return c;
}

int main(void){
    int temp;
    scanf("%d", &N);

    std::vector<cpx> f(200001);
    for(int i=0; i<N; ++i){
        scanf("%d", &temp);
        f[temp] = cpx(1, 0);
    }

    std::vector<cpx> result;
    result = multiply(f, f);

    scanf("%d", &M);

    int cnt = 0;
    for(int i=0; i<M; ++i){
        scanf("%d", &temp);
        if(result[temp].real() || f[temp].real()){ ++cnt; }
    }

    printf("%d", cnt);

    return 0;
}