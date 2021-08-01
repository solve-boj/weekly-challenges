/*
    124 나라의 숫자
    https://programmers.co.kr/learn/courses/30/lessons/12899
*/
function solution(n) {
    let conv=[4,1,2];
    var answer = '';
    while(n>0){
        answer = conv[n%3] + answer;
        n = Math.floor((n-1)/3);
    }
    return answer;
}