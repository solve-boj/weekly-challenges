/*
    예산
    https://programmers.co.kr/learn/courses/30/lessons/12982
*/

function solution(d, budget) {
    d.sort((a,b)=>a-b)
    for(let i in d)
        if(d[i] > budget)
            return +i
        else
            budget -= d[i]
    return d.length
}