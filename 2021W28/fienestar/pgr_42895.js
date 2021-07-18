/*
    N으로 표현
    https://programmers.co.kr/learn/courses/30/lessons/42895
*/
function solution(N, number)
{
    N = N + ''
    number = number + ''
    
    let p = [{}, {}]
    
    if(number == N)
        return 1
    
    p[1][N] = true
    
    for(let i=2; i<=8; ++i){
        let result = {}
        
        let check = v => {
            if(v == number)
                return true
            else{
                if(!isNaN(v) && isFinite(v))
                    result[v] = true
                return false
            }
        }
        
        if(check(N.repeat(i)))
            return i
        
        for(let j = 1; j != i; ++j)
            for(let k in p[j])
                for(let o in p[i-j]){
                    k = +k
                    o = +o
                    if(check(k+o) || check(Math.floor(k/o)) || check(k-o) || check(k*o))
                        return i
                }

        p.push(result)
    }
    
    return -1
}