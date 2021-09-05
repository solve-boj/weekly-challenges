/*
    N개의 최소공배수
    https://programmers.co.kr/learn/courses/30/lessons/12953
*/
function gcd(a,b)
{
    return a%b==0 ? b : gcd(b, a%b)
}

function lcm(a,b)
{
    return a*b/gcd(a,b)
}

function solution(arr) {
    return arr.reduce(lcm)
}