#include <iostream>
#include <cmath>
#include <iterator>
#include <list>
using namespace std;

int main(void){
    int pos[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    int n, k;
    cin >> n >> k;

    // 사과 위치 정보 입력
    list<pair<int, int> > snake(1, make_pair(1, 1));
    list<pair<int, int> > apple;
    int a, b;
    for(int i=0; i<k; ++i){
        cin >> a >> b;
        apple.push_back(make_pair(a, b));
    }

    // 회전 횟수 입력
    int l;
    cin >> l;
    pair<int, char> turn[l];
    for(int i=0; i<l; ++i){
        cin >> turn[i].first >> turn[i].second;
    }

    int flag = 0, dir = 0;
    for(int time = 1, turn_cnt = 0; !flag; time++){
        // 방향 전환 후 진행
        if (turn[turn_cnt].first == time - 1){
            dir = (turn[turn_cnt].second == 'D') ? (dir + 1) % 4 : (dir + 3) % 4;
            turn_cnt++;
        }
        snake.push_front(make_pair(snake.front().first + pos[dir][0], snake.front().second + pos[dir][1]));

        // 벽 치거나 자기 몸이랑 부딪히면 사망
        if((snake.front().first <= 0 || snake.front().first > n) || (snake.front().second <= 0 || snake.front().second > n)){
            flag = 1;
        }
        list<pair<int, int> >::iterator it = next(snake.begin());
        for(; it != snake.end(); it++){
            if (*it == snake.front()){
                flag = 1;
                break;
            }
        }

        // 사망 시 시간 출력 후 게임 종료
        if(flag){
            printf("%d", time);
        }

        // 사과 먹으면 사과 제거 후 길이 증가. 안 먹으면 꼬리 한 칸 제거
        for(it = apple.begin(); it != apple.end(); it++){
            if (*it == snake.front()){
                apple.remove(*it);
                break;
            }
        }
        if (it == apple.end()){
            snake.pop_back();
        }

    }

    return 0;
}
