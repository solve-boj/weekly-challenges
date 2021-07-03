#include <iostream>
#include <iterator>
#include <list>
#include <string>
using namespace std;

int main(void){
    list<char> editor;
    list<char>::iterator cursor;

    cursor = editor.end();
    string init;
    cin >> init;
    for(char& c : init){
        editor.push_back(c);
    }

    int lines;
    cin >> lines;
    cin.ignore();

    string cmd;
    for(int i=0; i<lines; i++){
        getline(cin, cmd);
        switch(cmd[0]){
        case 'L':
            if(cursor != editor.begin()){
                cursor = prev(cursor);
            }
            break;
        case 'D':
            if(cursor != editor.end()){
                cursor = next(cursor);
            }
            break;
        case 'B':
            if(cursor != editor.begin()){
                editor.erase(prev(cursor));
            }
            break;
        case 'P':
            editor.insert(cursor, cmd[2]);
            break;
        }
    }

    for(list<char>::iterator it = editor.begin(); it != editor.end(); it++){
        cout << *it;
    }
    return 0;
}
