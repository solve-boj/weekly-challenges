/*
    가장 큰 수
    https://programmers.co.kr/learn/courses/30/lessons/42746
*/
function solution(numbers) {
    
    let answer = numbers.map((e)=>e+'').sort(function(a,b){
        return (a+b)>(b+a)?-1:1
    }).join("")
    if(answer[0]=='0')return "0"
    return answer
}