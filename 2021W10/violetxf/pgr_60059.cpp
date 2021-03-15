/*
    자물쇠와 열쇠
    https://programmers.co.kr/learn/courses/30/lessons/60059
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int keysize = key.size();
    int locksize = lock.size();
    int t = 4;
    while(t--){
        // for(int i=0;i<keysize;i++){
        //     for(int k=0;k<keysize;k++){
        //         cout<<key[i][k]<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(int row=keysize-1; row>-locksize;row--){
            for(int col=keysize-1; col>-locksize;col--){
                bool fits = true;
                for(int i=0;i<locksize;i++){
                    for(int k=0;k<locksize;k++){
                        int r = row+i;
                        int c = col+k;
                        int lock_info = lock[i][k];
                        if(r<0||c<0||r>=keysize||c>=keysize){
                            if(lock_info==0){
                                fits = false;
                                break;
                            }
                            continue;
                        }
                        
                        int key_info = key[r][c];
                        if(lock_info==key_info){
                            fits = false;
                            break;
                        }
                    }
                    if(!fits)break;
                }
                if(fits)return true;

            }
        }
        vector<vector<int>>temp(keysize,vector<int>(keysize,0));
        for(int i=0;i<keysize;i++){
            for(int k=0;k<keysize;k++){
                temp[k][keysize-i-1]=key[i][k];
            }
        }
        copy(temp.begin(),temp.end(),key.begin());
    }
    return false;
}
int main(){
    cout<<solution({{0,0,0},{1,0,0},{0,1,1}},{{1,1,1},{1,1,0},{1,0,1}});
}