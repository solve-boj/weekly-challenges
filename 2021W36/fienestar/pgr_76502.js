/*
    괄호 회전하기
    https://programmers.co.kr/learn/courses/30/lessons/76502
*/
function solution(s)
{
    if(s.length & 1)
        return 0
    
    let answer = 0
    
    for(let i in s){
        let stack = []
        let valid = true
        for(let j in s){
            let c = s[(+i + +j)%s.length]
            
            if(['[','{','('].includes(c))
                stack.push(c)
            
            else if(['[','{','('][[']','}',')'].indexOf(c)] == stack[stack.length - 1])
                stack.pop()
            
            else{
                valid = false
                break
            }
        }
        
        if(valid) ++ answer
    }
    
    return answer
}
