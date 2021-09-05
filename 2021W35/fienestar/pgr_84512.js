/*
    5주차
    https://programmers.co.kr/learn/courses/30/lessons/84512
*/
// 6 ** 5 naive
function solution(word)
{
    let k = 0;
    let str = []
    function find()
    {   
        if(str.join('') === word)
            return k;
        
        if(str.length === 5){
            ++k;
            return;
        }
        
        ++k;
        
        for(const ch of "AEIOU") {
            str.push(ch)
            const result = find()
            if(result) return result;
            str.pop()
        }
    }
    
    return find()
}