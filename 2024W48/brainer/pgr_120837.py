# 개미 군단
# https://school.programmers.co.kr/learn/courses/30/lessons/120837?language=python3

def solution(hp):
    num_general = 0
    num_soldir = 0
    num_worker = 0
    
    num_general = hp // 5
    hp = hp - num_general * 5
    
    if hp > 0:
        num_soldir = hp // 3
        hp = hp - num_soldir * 3
    
    if hp > 0:
        num_worker = hp
        hp = hp - num_worker
    
    answer = num_general + num_soldir + num_worker
    return answer
