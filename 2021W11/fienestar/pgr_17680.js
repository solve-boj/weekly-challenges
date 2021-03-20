/*
    캐시
    https://programmers.co.kr/learn/courses/30/lessons/17680
*/
function solution(cacheSize, cities) {
    let cache = []
    let answer = 0
    
    if(cacheSize == 0)return 5 * cities.length
    
    for(let city of cities){
        city = city.toUpperCase()
        
        if(cache.includes(city)){
            cache.splice(cache.indexOf(city),1)
            answer += 1
        }else
            answer += 5
        
        if(cache.length == cacheSize)
            cache.shift()
        
        cache.push(city)
    }
    
    return answer;
}