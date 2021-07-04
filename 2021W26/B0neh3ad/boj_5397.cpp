#include <iostream>
#include <iterator>
#include <string>
#include <list>
using namespace std;

int main(void){
    int T;
    cin >> T;
    cin.ignore();

    for(int i=0; i<T; ++i){
        list<char> password;
        list<char>::iterator cursor;
        cursor = password.end();

        string log_str;
        getline(cin, log_str);

        int len = log_str.length();
        for(int j=0; j<len; ++j){
            switch(log_str[j]){
            case '<':
                if(cursor != password.begin()){
                    cursor = prev(cursor);
                }
                break;

            case '>':
                if(cursor != password.end()){
                    cursor = next(cursor);
                }
                break;

            case '-':
                if(cursor != password.begin()){
                    password.erase(prev(cursor));
                }
                break;

            default:
                password.insert(cursor, log_str[j]);
                break;
            }
        }

        for(list<char>::iterator it = password.begin(); it != password.end(); it++){
            printf("%c", *it);
        }
        printf("\n");
    }

    return 0;
}
