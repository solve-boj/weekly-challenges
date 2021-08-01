/*
    오픈채팅방
    https://programmers.co.kr/learn/courses/30/lessons/42888
*/
function solution(record) {
    var answer = [];
    let table = {};
    for(let r of record){
        let spl = r.split(" ");
        let cmd = spl[0];
        let uid = spl[1];
        let name = spl[2];
        switch(cmd){
            case "Enter":
                answer.push({txt:"님이 들어왔습니다.", uid:uid})
                table[uid] = name;
            break;
            case "Leave":
                answer.push({txt:"님이 나갔습니다.", uid:uid})
            break;
            case "Change":
                table[uid] = name;
            break;
        }
    }
    for(let i = 0; i<answer.length; i++){
        
        answer[i] = table[answer[i]["uid"]]+answer[i]["txt"];
    }
    
    return answer;
}