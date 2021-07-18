/*
    가장 큰 수
    https://programmers.co.kr/learn/courses/30/lessons/42746
*/
function solution(numbers)
{
    let answer = numbers.map(v=>v+"").sort((a,b)=>(b+a) - (a+b)).join('')
    if(answer[0] == '0')
        return '0'
    else
        return answer
}