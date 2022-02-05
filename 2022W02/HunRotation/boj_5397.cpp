/*
    키로거
    https://www.acmicpc.net/problem/5397
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

list<char> buffer;
int N;
string command;

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> command;
        auto cursor = buffer.end();
        for(char ch: command) {
            switch(ch) {
                case '<':
                    if (buffer.size() > 0 && cursor != buffer.begin()) {
                        cursor--;
                    }
                    break;
                case '>':
                    if (buffer.size() > 0 && cursor != buffer.end()) {
                        cursor++;
                    }
                    break;
                case '-':
                    if (buffer.size() > 0 && cursor != buffer.begin()) {
                        cursor--;
                        cursor = buffer.erase(cursor);
                    }
                    break;
                default:
                    if(buffer.size() == 0 || cursor == buffer.end()) buffer.push_back(ch);
                    else {
                        buffer.insert(cursor, ch);
                    }
            }

        }

        for(char ch: buffer) {
            cout << ch;
        }
        cout << endl;
        buffer.clear();
    }
}