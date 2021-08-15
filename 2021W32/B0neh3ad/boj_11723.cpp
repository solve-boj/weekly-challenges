/*
    [미포함] 집합
    https://www.acmicpc.net/problem/11723
*/
#include <cstdio>
#include <cstring>

int main(void){
    int m;
    long long set = 0;
    scanf("%d", &m);

    char cmd[10];
    long long val;
    for(int i=0; i<m; ++i){
        scanf(" %s", cmd);
        if(strcmp(cmd, "all")){
            scanf(" %lld", &val);
            if(!strcmp(cmd, "add")){
                set |= (1 << val);
            }
            else if(!strcmp(cmd, "remove")){
                set &= ~(1 << val);
            }
            else if(!strcmp(cmd, "check")){
                printf((set & (1 << val)) ? "1\n" : "0\n");
            }
            else if(!strcmp(cmd, "toggle")){
                set ^= (1 << val);
            }
            else if(!strcmp(cmd, "empty")){
                set = 0;
            }
        }
        else{
            set = (1 << 21) - 2;
        }
    }
    return 0;
}
/*
    scanf 쓸 때는 절대 string 쓰지 말자
    아니 뭔 이런 거에 4트씩이나...
    시간 줄이려면 비트마스킹이나 check 배열 쓰는 방향으로...
*/