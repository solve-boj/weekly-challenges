/*
    순위
    https://programmers.co.kr/learn/courses/30/lessons/49191
*/
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> matchData(n+1, vector<bool>(n+1, false));
    for(auto k : results){
        int w = k[0];
        int l = k[1];
        matchData[w][l] = true;
    }
    for(int i=1; i<=n; i++){
        for(int k=1; k<=n; k++){
            for(int p=1; p<=n; p++){
                if(matchData[k][i] && matchData[i][p]){
                    matchData[k][p] = true;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        int dataCnt = 0;    
        for(int k=1; k<=n; k++){
            if(matchData[i][k]||matchData[k][i]){
                dataCnt++;
            }
        }
        if(dataCnt == n-1){
            answer++;
        }
    }
    return answer;
}
