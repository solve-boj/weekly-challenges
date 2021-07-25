#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string do1[N];
    map<string, int> do2;
    for(int i=0; i<N; ++i){
        cin >> do1[i];
        do2.insert(make_pair(do1[i], i));
    }

    string temp;
    for(int i=0; i<M; ++i){
        cin >> temp;
        if(temp[0] <= '9')
            cout << do1[atoi(temp.data()) - 1] << '\n';
        else
            cout << do2[temp] + 1 << '\n';
    }
    return 0;
}