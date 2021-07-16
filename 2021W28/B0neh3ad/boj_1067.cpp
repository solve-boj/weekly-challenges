#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &f, cpx w){
    int n = f.size();
    // base case
    if(n == 1) { return; }

    vector<cpx> even(n/2), odd(n/2);

    // 1. 다항식 쪼개기
    for(int i=0; i<n; ++i){
        (i%2 ? odd : even)[i/2] = f[i]; // 여기 틀리지 않게 조심!!!!
    }

    // 2. divide
    FFT(even, w*w);
    FFT(odd, w*w);

    // 3. conquer
    cpx wp(1, 0);
    for(int i=0; i<n/2; ++i){
        f[i] = even[i] + wp*odd[i];
        f[i+n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b){
    int n = 1;
    while(n < a.size()+1 || n < b.size()+1) n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    vector<cpx> c(n);

    cpx w(cos(2*PI/n), sin(2*PI/n));

    // 1. FFT
    FFT(a, w);
    FFT(b, w);

    // 2. multiply
    for(int i=0; i<n; ++i){
        c[i] = a[i]*b[i];
    }

    // 3. IFFT
    FFT(c, cpx(1, 0)/w);
    for(int i=0; i<n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }

    return c;
}

int main(void){
    int n;
    cin >> n;
    
    vector<cpx> a(2*n);
    vector<cpx> b(2*n);

    int temp;
    for(int i=0; i<n; ++i){
        cin >> temp;
        a[i+n] = a[i] = cpx(temp, 0);
    }
    for(int i=0; i<n; ++i){
        cin >> temp;
        b[n-1-i] = cpx(temp, 0);
    }

    vector<cpx> c;
    c = multiply(a, b);

    int s = 0;
    for(int i=n-1; i<2*n-1; ++i) { s = max(s, int(c[i].real())); }
    cout << s;
    
    return 0;
}

/*
    1.
    다항식의 곱은 대체로 항이 반대 순서로 곱해지므로,
    Y를 뒤집으면 동일 순서로 각 항을 곱할 수 있을 것이다.
    2. '순환 이동'과 같은 형태는
    수열을 뒤에 하나 더 이어붙임으로써 쉽게 구현할 수 있다.
    3. 일단 1, 2의 아이디어로 손으로 풀어본 뒤, 문제가 생기면 피드백한다.

    오늘 배운 것
    - c++은 python마냥 max(iterable) 식으로 못 쓴다
    - 저 위에 FFT 오류 나기 쉬운 line...
    1) odd even 위치
    2) index가 i인지 i/2인지
    잘 구분!!
*/