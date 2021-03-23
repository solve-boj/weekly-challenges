/*
    압축
    https://programmers.co.kr/learn/courses/30/lessons/17684
*/
function char(c)
{
    if(c.charCodeAt)
        return c.charCodeAt(0);
    else
        return String.fromCharCode(c)
}

function make()
{
    make.i = make.i || 0
    return {idx: ++make.i, next: {}}
}

function set_default(obj,idx,val)
{
    return obj[idx] = obj[idx] || val
}

function find(str)
{
    let dict = set_default(find,'dict',{idx:0, next: {}})
    
    for(let i in str){
        if(!dict.next[str[i]]){
            dict.next[str[i]] = make()
            return [i,dict.idx]
        }
        
        dict = dict.next[str[i]]
    }
    return [str.length, dict.idx]
}

function solution(msg) {
    let dict = {}
    for(let i = char('A'); i<=char('Z'); ++i)
        find(char(i))
    
    let i = 0
    let answer = []
    while( msg.length){
        let rslt = find(msg)
        msg = msg.substr(rslt[0])
        answer.push(rslt[1])
    }
    return answer;
}