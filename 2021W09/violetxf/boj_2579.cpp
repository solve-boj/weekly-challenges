/*
    계단 오르기
    https://www.acmicpc.net/problem/2579
*/
#include <iostream>
#include <algorithm>
using namespace std;
int dp[301][2]; //0 for non seq, 1 for seq

int main(){
    int n;
    cin>>n;
    int stairs[301];
    for(int i=0;i<n;i++){
        int score;
        cin>>score;
        stairs[i]=score;
    }
    dp[0][0] = stairs[0];
    dp[0][1] = stairs[0];
    for(int i=1;i<n;i++){

        // notation: prev status _ needs jump
        int seq_jmp = 0;
        if(i-2>=0){
            seq_jmp = dp[i-2][1];
        }
        int nonseq_jmp = 0;
        if(i-2>=0){
            nonseq_jmp = dp[i-2][0];
        }
        int nonseq_nojmp;
        nonseq_nojmp = dp[i-1][0];
        dp[i][0] = max(seq_jmp, nonseq_jmp)+stairs[i];
        dp[i][1] = nonseq_nojmp+stairs[i];
    }
    cout<<max(dp[n-1][0],dp[n-1][1]);
    

}