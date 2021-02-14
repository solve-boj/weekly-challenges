/*
    튜플
    https://programmers.co.kr/learn/courses/30/lessons/64065
*/

function solution(s) {
    var answer = [];
    s = JSON.parse(s.replace(/\{/g,'[').replace(/\}/g,']'))
    s = s.sort((a,b)=>a.length-b.length)
    
    for(let arr of s)
        answer.push(arr.find(v=>!answer.includes(v)))
    return answer;
}