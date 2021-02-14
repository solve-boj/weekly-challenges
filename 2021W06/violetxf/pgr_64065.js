/*
    튜플
    https://programmers.co.kr/learn/courses/30/lessons/64065
*/
function solution(s) {
    var answer = [];
    let input = JSON.parse(s.replace(/\{/g,"[").replace(/\}/g,"]"));
    input.sort(function(a, b){
        return a.length - b.length;
    });
    answer = input[0];
    for(let i=1;i<input.length;i++){
        let temp = input[i];
        for(let k=0;k<answer.length;k++){
            let idx = temp.indexOf(answer[k]);
            if(idx!=-1){
                temp.splice(idx, 1);
            }
        }
        answer.push(temp[0]);
    }
    return answer;
}