/*
    유기농 배추
    https://www.acmicpc.net/problem/1012
*/
#include <bits/stdc++.h>

using namespace std;

size_t solve()
{
    size_t M,N;
    cin >> M >> N;

    static bool field[50][50];
    fill((bool*)field,(bool*)field+50*50,false);

    size_t K;
    cin >> K;
    while(K--){
        size_t X,Y;
        cin >> X >> Y;
        field[X][Y] = true;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t T;
    cin >> T;
    while(T--)
        cout << solve() << "\n";
}