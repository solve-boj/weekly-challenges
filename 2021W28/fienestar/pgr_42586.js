/*
    기능개발
    https://programmers.co.kr/learn/courses/30/lessons/42586
*/
function solution(progresses, speeds) {
    let answer = [];
    let day = -1

    for(let i in progresses){
        let need = Math.ceil((100-progresses[i])/speeds[i])
        if(need <= day)
            answer[answer.length - 1]++
        else{
            answer.push(1)
            day = need
        }
    }
    
    return answer;
}