/*
    캐시
    https://programmers.co.kr/learn/courses/30/lessons/17680
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Cache{
private:
    int size;
    int cursor;
    vector<string> caches;
public:
    Cache(int size){
        this->size = size;
        caches.resize(size);
    }
    bool push_new(string data){
        auto it = search(data);
        bool has = it!=caches.end();
        if(has){
            caches.erase(it);
        }else{
            caches.erase(caches.begin());
        }
        caches.push_back(data);
        return has;
    }
private:
    vector<string>::iterator search(string key){
        return find(caches.begin(), caches.end(), key);
        
    }
};
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize==0)return cities.size()*5;
    Cache cache(cacheSize);
    for(int i=0;i<cities.size();i++){
        string data = cities[i];
        transform(data.begin(), data.end(), data.begin(), [](unsigned char c){return tolower(c);});
        if(cache.push_new(data)){
            ++answer;
        } else {
            answer+=5;
        }
    }
    return answer;
}
