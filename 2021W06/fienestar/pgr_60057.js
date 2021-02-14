/*
    문자열 압축
    https://programmers.co.kr/learn/courses/30/lessons/60057?language=javascript
*/

function compress(s, len)
{
    let before = ""
    let result = ""
    let n = 0
    
    for(let i = 0; i <= s.length; i += len){
        let str = s.slice(i,i+len)
        if(str == before)
            ++n
        else{
            if(n)result += n+1
            result += str
            before = str
            n = 0
        }
    }
    return result
}

function solution(s) {
    var answer = Infinity;
    for(let i = 1; i <= s.length; ++i)
        answer = Math.min(answer,compress(s,i).length)
    return answer;
}