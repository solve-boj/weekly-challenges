/*
    후보키
    https://programmers.co.kr/learn/courses/30/lessons/42890
*/
function select(tuple, selector){ //selector->비트 (ex: 9->0b1001->1,4번째 칼럼 select)
    let result='';
    for(let i=0;i<8;i++){
        let bit = 1<<i;
        if(selector&bit){
            result+=tuple[i]+' ';
        }
    }
    return result;
}
function isUnique(relation, selector){
    let history=[];
    for(let tuple of relation){
        let str = select(tuple, selector);
        if(history.includes(str)) return false;
        history.push(str);
    }
    return true;
}
function checkSubset(verifiedSelectors, selector){
    for(let k of verifiedSelectors){
        if((k|selector)==selector)return true;
    }
    return false;
}
function solution(relation) {
    let fullBits = Math.pow(2, relation[0].length)-1;
    let verifiedSelectors = [];
    for(let selector=1;selector<=fullBits;selector++){
        if(!checkSubset(verifiedSelectors, selector) && isUnique(relation, selector)){
            verifiedSelectors.push(selector);
        }
    }
    return verifiedSelectors.length;
}