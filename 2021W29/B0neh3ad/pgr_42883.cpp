#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs){
    return (lhs.first != rhs.first) ? (lhs.first > rhs.first) : (lhs.second < rhs.second);
}

string solution(string number, int k) {
    string answer = "";
    vector<pair<char, int> > num(number.size());
    
    for(int i=0; i<number.size(); ++i)
        num[i] = make_pair(number[i], i);

    sort(num.begin(), num.end(), cmp);

    int stand = num.size() - k;
    for(int i=0; i<num.size(); ++i){
        cout << num[i].second << " vs " << stand << " ";
        if(num[i].second >= stand){
            answer += num[i].first;
            stand = num[i].second;
        }
        cout << answer << endl;
    }

    return answer;
}

int main(void){
    cout << solution("1924", 2);
    return 0;
}