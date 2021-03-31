/*
    방금그곡
    https://programmers.co.kr/learn/courses/30/lessons/17683
*/
function parseDate(str)
{
    let splited = str.split(':')
    return 60*splited[0] + +splited[1]
}

function replaceMusicCode(code)
{
    for(let c of "ABCDEFG")
        code = code.replace(new RegExp(c+'#','g'),c.toLowerCase())
    
    return code
}

function solution(m, musicinfos)
{
    musicinfos = musicinfos.map(music=>{
        let splited = music.split(',')
        let len = parseDate(splited[1])-parseDate(splited[0])
        let title = splited[2]
        let data = replaceMusicCode(splited[3])
        if(len > data.length)
            data += data.repeat((len / data.length - 1)|0) + data.substr(0,len % data.length)
        else
            data = data.substr(0,len)
        
        return [title,data]
    })
    
    m = replaceMusicCode(m)
    
    let max_title = ""
    let max_length = 0
    for(let music of musicinfos)
        if(music[1].includes(m) && music[1].length > max_length){
            max_length = music[1].length
            max_title = music[0]
        }
    
    if(max_length)
        return max_title;
    else
        return "(None)"
}