/*
    N진수 게임
    https://programmers.co.kr/learn/courses/30/lessons/17687
*/
function solution(n, t, m, p) {
    --p
    
    let out = ""
    let i = 0
    let end = t*m+p
    while(out.length < end){
        out += i.toString(n)
        ++i
    }
    out = out.toUpperCase()
    
    let answer = ""
    for(i = p; i != end; i += m)
        answer += out[i]
    
    return answer;
}