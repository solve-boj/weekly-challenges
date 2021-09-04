/*
    모음 사전
    https://programmers.co.kr/learn/courses/30/lessons/84512
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int> num_length = {1, 6, 31, 156, 781};
    map<char, int> vowels= {{'A', 0}, {'E', 1}, {'I', 2},
    {'O', 3}, {'U', 4}};

    int L = word.size();
    for(int i=0;i<L;i++) {
        answer += vowels[word[i]] * num_length[4-i] + 1;
    }

    return answer;
}

int main() {
    string str = "EIO";
    printf("%d", solution(str));
}

// keyword: 문자열
// 시간복잡도: O(word.size())
/*
idea: k개 이하 길이를 가진 단어의 개수를 미리 계산해 num_length로 사용
*/