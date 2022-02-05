/*
    뱀
    https://www.acmicpc.net/problem/3190
*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int N, K, L;
list<pair<int, int>> snake;
vector<pair<int, int>> apples;
vector<pair<int, char>> commands;
bool board[100][100] = {true, };
const pair<int, int> dirlist[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    int x, y, t, curt = 0;
    char c;
    scanf("%d", &N);
    scanf("%d", &K);
    for(int i=0;i<K;i++) {
        scanf("%d %d", &x, &y);
        apples.push_back({x-1, y-1});
    }
    scanf("%d", &L);
    for(int i=0;i<L;i++) {
        scanf("%d %c", &t, &c);
        commands.push_back({t, c});
    }

    snake.push_front({0, 0});
    /*
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("------------\n");
    for(auto i: snake) {
        printf("%d %d\n", i.first, i.second);
    }
    printf("%d\n", curt);
    printf("------------\n");
    */
    int cursor = 0, dir = 0;
    bool flag = false;
    while((*(snake.begin())).first >= 0 && (*(snake.begin())).first < N &&
    (*(snake.begin())).second >= 0 && (*(snake.begin())).second < N && 
    !board[(*(snake.begin())).first+dirlist[dir].first][(*(snake.begin())).second+dirlist[dir].second]) {
        
        board[(*(snake.begin())).first+dirlist[dir].first][(*(snake.begin())).second+dirlist[dir].second] = true;
        snake.push_front({(*(snake.begin())).first+dirlist[dir].first, (*(snake.begin())).second+dirlist[dir].second});
        for(auto iter = apples.begin();iter!=apples.end();iter++) {
            if((*(snake.begin())).first == (*iter).first && (*(snake.begin())).second == (*iter).second) {
                flag = true;
                apples.erase(iter);
                break;
            }
        }

        if(!flag) {
            board[(*(snake.rbegin())).first][(*(snake.rbegin())).second] = false;
            snake.pop_back();
        }

        curt++;
        if(cursor < commands.size() && curt == commands[cursor].first) {
            dir = (dir + 2 + ((commands[cursor].second=='D')?-1:1)) % 4;
            cursor++;
        }
        flag = false;
        /*
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("------------\n");
        for(auto i: snake) {
            printf("%d %d\n", i.first, i.second);
        }
        printf("%d %d %d\n", curt, cursor, dir);
        printf("------------\n");*/
    }
    if ((*(snake.begin())).first >= 0 && (*(snake.begin())).first < N &&
    (*(snake.begin())).second >= 0 && (*(snake.begin())).second < N && 
    board[(*(snake.begin())).first+dirlist[dir].first][(*(snake.begin())).second+dirlist[dir].second]) {
        cout << curt+1;
    }
    else cout << curt;
}