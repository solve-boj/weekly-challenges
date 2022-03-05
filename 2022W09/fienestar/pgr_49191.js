/*
    순위
    https://programmers.co.kr/learn/courses/30/lessons/49191
*/

function solution(n, results)
{
    let answer = 0
    let has_route = new Array(n).fill(null).map(v=>new Array(n).fill(false))
    
    for(let result of results)
        has_route[result[0]-1][result[1]-1] = true

    for(let k in has_route)
        for(let a in has_route[k])
            if(has_route[a][k])
                for(let b in has_route[k])
                    if(has_route[k][b])
                        has_route[a][b] = true
    
    for(let i in has_route){
        let win = has_route[i].filter(v=>v).length
        let lose = has_route.filter(v=>v[i]).length
        answer += (win + lose + 1 == n)
    }
    return answer
}