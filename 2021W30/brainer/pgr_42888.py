# 오픈채팅방
# https://programmers.co.kr/learn/courses/30/lessons/42888

def solution(record):
    answer = []
    log = []
    id_nic = {}
    for i in record:
        chat = i.split()

        if chat[0] == "Enter":
            id_nic[chat[1]] = chat[2]
            log.append([chat[1], "In"])
            # answer.append(chat[2] + "들어왔습니다.")
        elif chat[0] == "Leave":
            # answer.append(id_nic[chat[1]] + "나갔습니다.")
            log.append([chat[1], "Out"])
        else:
            id_nic[chat[1]] = chat[2]
        
    for i, v in enumerate(log):
        if v[1] == "In":
            answer.append(id_nic[v[0]] + "님이" + " 들어왔습니다.")
        else:
            answer.append(id_nic[v[0]] + "님이" + " 나갔습니다.")
    
    return answer
