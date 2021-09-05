/*
    모음 사전
    https://programmers.co.kr/learn/courses/30/lessons/84512
*/
let order = {};
let arr = ['A', 'E', 'I', 'O', 'U']
let number = 1;
function createWord(cursor, length, current){
    if(cursor == length) return
    for(let i=0; i<5; i++){
        
        order[current+arr[i]] = number++;
        createWord(cursor+1, length, current+arr[i])
    }
    
}
function solution(word) {
    createWord(0, 5, "");
    return order[word];
}