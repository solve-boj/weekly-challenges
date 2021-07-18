/*
    기능개발
    https://programmers.co.kr/learn/courses/30/lessons/42586
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> timeleft(progresses.size(),0);
    for(int i=0;i<progresses.size();i++){
        timeleft[i] = (100-progresses[i])/speeds[i] + ((100-progresses[i])%speeds[i]!=0);
    }
    int selected = timeleft[0];
    int count = 1;
    for(int i=1;i<progresses.size();i++){
        int current = timeleft[i];
        if(current>selected){
            selected = current;
            answer.push_back(count);
            count = 1;
            continue;
        }
        ++count;
    }
    answer.push_back(count);
    return answer;
}