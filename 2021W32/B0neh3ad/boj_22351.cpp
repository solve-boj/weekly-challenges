/*
    [미포함] 수학은 체육과목 입니다 3
    https://www.acmicpc.net/problem/22351
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int digits(int num){
    int answer = 0;
    while(num){
        num /= 10;
        ++answer;
    }
    return answer;
}

int main(void){
    string s;
    cin >> s;

    int a, b;
    
    a = b = 1000;
    int temp_b = 1000;
    for(int i=1; i<=3; ++i){
        if(s.size() >= i && a > stoi(s.substr(0, i))){
            bool flag = true;
            temp_b = stoi(s.substr(0, i));
            for(int j=0; j<s.size(); ++temp_b){
                if(temp_b != stoi(s.substr(j, digits(temp_b)))){
                    flag = false;
                    break;
                }
                j += digits(temp_b);
            }
            if(flag){
                b = --temp_b;
                a = stoi(s.substr(0, i));
            }
        }
    }

    cout << a << " " << b;

    return 0;
}
/*
    첨에는 그냥 무지성으로 맨 앞 몇 자리 비교해서 a값 결정하고
    문자열 쭉 따라가면서 b값 정하는 방식으로 했는데
    567568 같은 반례가 있어서
    그냥 맨 앞 1, 2, 3자리 잘라서 각각 검토하는 식으로 돌렸다.
    그래봐야 O(n).
*/