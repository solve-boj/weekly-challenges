# 완주하지 못한 선수
# https://programmers.co.kr/learn/courses/30/lessons/42576

def solution(participant, completion):
    answer = {}
    
    for i in participant:
        if i in answer:
            answer[i] += 1
        else:
            answer[i] = 1
    
    for i in completion:
        answer[i] -= 1
    
    return [key for key, value in answer.items() if value != 0][0]
