/*
    피보나치 수
    https://programmers.co.kr/learn/courses/30/lessons/12945
*/
function solution(n)
{
    let fibo = [0,-1,1]
    for(let i=0; i<=n; ++i)
        fibo[i%3] = (fibo[(i+2)%3] + fibo[(i+1)%3]) % 1234567
    return fibo[n%3]
}