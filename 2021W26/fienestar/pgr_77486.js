/*
    다단계 칫솔 판매
    https://programmers.co.kr/learn/courses/30/lessons/77486
*/
function create_array(n, v)
{
    let result = []
    result.length = n
    result.fill(v)
    return result
}

function solution(enroll, referral, seller, amount)
{
    let answer = create_array(enroll.length, 0)
    let parent = create_array(enroll.length + 1, enroll.length)
    
    let idx_of = {
        "-": enroll.length
    }
    
    for(let i in enroll)
        idx_of[enroll[i]] = i
    
    for(let i in referral)
        parent[i] = idx_of[referral[i]]
    
    for(let i in amount){
        let money = amount[i] * 100
        let to = idx_of[seller[i]]
        
        do{
            answer[to] += money - ((money / 10) | 0)
            money = (money / 10) | 0
            to = parent[to]
        }while(to != parent[to] && money)
    }
    
    return answer
}