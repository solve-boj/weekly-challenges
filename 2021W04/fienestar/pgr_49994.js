/*
    방문 길이
    https://programmers.co.kr/learn/courses/30/lessons/49994
*/

function solution(dirs) {
    let x = 0,y = 0;
    let mx = { U: +1, D: -1, L: +0, R: +0}
    let my = { U: +0, D: +0, L: +1, R: -1}
    let memo = {}
    let answer = 0
    
    for(let i in dirs){
        let dx = x+mx[dirs[i]]
        let dy = y+my[dirs[i]]
        
        if(Math.abs(dx) == 6 || Math.abs(dy) == 6)
            continue
        
        let idx = [x,y,dx,dy].join('$')
        answer += !memo[idx]
        memo[idx]=true
        memo[[dx,dy,x,y].join('$')] = true
        x = dx
        y = dy
    }
    return answer;
}