/*
    멀쩡한 사각형
    https://programmers.co.kr/learn/courses/30/lessons/62048
*/
using namespace std;
using ll = long long;

ll solution(int w, int h)
{
    ll answer = 1ll * w * h;
    for(ll i=0; i!=w; ++i)
        answer -= h*(i+1)/w + (h*(i+1)%w != 0)- h*i/w;
    return answer;
}