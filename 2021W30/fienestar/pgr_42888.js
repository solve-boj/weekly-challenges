/*
    오픈채팅방
    https://programmers.co.kr/learn/courses/30/lessons/42888
*/
function solution(record) {
    let uid2name = {};
    return record.map(element=>{
        let msg = element.split(' ');
        switch(msg[0])
        {
            case 'Enter':
                uid2name[msg[1]]=msg[2]
                return '{'+msg[1]+'}님이 들어왔습니다.'
            case 'Leave':
                return '{'+msg[1]+'}님이 나갔습니다.'
            case 'Change':
                uid2name[msg[1]]=msg[2]
                return ''
        }
    }).filter(
        s=>s
    ).map(
        el=>el.replace(/\{([^}]+)\}/, (a,b)=>uid2name[b])
    )
}